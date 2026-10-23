"""Offline regressions for difficulty resolution and generated totals."""
import importlib.util
import io
import json
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch
import xml.etree.ElementTree as ET

spec = importlib.util.spec_from_file_location("update_readme", Path(__file__).with_name("update_readme.py"))
generator = importlib.util.module_from_spec(spec)
spec.loader.exec_module(generator)


class DifficultyTests(unittest.TestCase):
    def setUp(self):
        self.item = {"slug": "eating-bananas", "folder_relpath": "Data Structures & Algorithms/eating-bananas",
                     "sol_relpath": None}
        self.medium = {"title": "Koko Eating Bananas", "difficulty": "Medium",
                       "category": "Array / Binary Search", "source": "https://leetcode.com/problems/koko-eating-bananas/"}
        generator.load_neetcode_catalog.cache_clear()

    def test_failed_lookup_is_pending_and_retried(self):
        cache = {}
        with patch.object(generator, "fetch_problem_info", side_effect=[None, self.medium]) as fetch:
            self.assertEqual(generator.resolve_metadata(self.item, cache)["difficulty"], "Pending")
            self.assertNotIn("eating-bananas", cache)
            self.assertEqual(generator.resolve_metadata(self.item, cache)["difficulty"], "Medium")
            self.assertEqual(fetch.call_count, 2)
        self.assertEqual(cache["eating-bananas"], self.medium)

    def test_legacy_easy_guess_is_rechecked(self):
        cache = {"eating-bananas": {"title": "Eating Bananas", "difficulty": "Easy", "category": "Algorithms"}}
        with patch.object(generator, "fetch_problem_info", return_value=self.medium) as fetch:
            self.assertEqual(generator.resolve_metadata(self.item, cache)["difficulty"], "Medium")
            fetch.assert_called_once_with("eating-bananas")

    def test_legacy_guess_is_removed_when_refresh_fails(self):
        cache = {"eating-bananas": {"difficulty": "Easy", "category": "Algorithms"}}
        with patch.object(generator, "fetch_problem_info", return_value=None):
            self.assertEqual(generator.resolve_metadata(self.item, cache)["difficulty"], "Pending")
        self.assertEqual(cache, {})

    def test_verified_cache_survives_network_outage(self):
        cache = {"eating-bananas": self.medium}
        with patch.object(generator, "fetch_problem_info", side_effect=AssertionError("Should not fetch")):
            self.assertEqual(generator.resolve_metadata(self.item, cache), self.medium)

    def test_readme_difficulty_takes_precedence(self):
        item = {**self.item, "readme_diff": "Medium", "readme_title": "Koko Eating Bananas"}
        cache = {"eating-bananas": {"difficulty": "Easy", "category": "Algorithms"}}
        with patch.object(generator, "fetch_problem_info", side_effect=AssertionError("Should not fetch")):
            self.assertEqual(generator.resolve_metadata(item, cache)["difficulty"], "Medium")
        self.assertTrue(cache["eating-bananas"]["source"].endswith("README.md"))

    def test_invalid_cached_difficulty_is_not_classified(self):
        for invalid in (None, "", "Unknown", "Expert"):
            with self.subTest(invalid=invalid), patch.object(generator, "fetch_problem_info", return_value=None):
                cache = {"eating-bananas": {"difficulty": invalid, "category": "Binary Search"}}
                self.assertEqual(generator.resolve_metadata(self.item, cache)["difficulty"], "Pending")

    def test_api_uses_alias_and_requires_valid_difficulty(self):
        for difficulty in (None, "Expert", "Medium"):
            payload = {"data": {"question": {"title": "Koko Eating Bananas", "difficulty": difficulty,
                                            "topicTags": [{"name": "Binary Search"}]}}}
            with self.subTest(difficulty=difficulty), patch.object(generator.urllib.request, "urlopen",
                    return_value=io.BytesIO(json.dumps(payload).encode())) as fetch:
                result = generator.fetch_leetcode_info("eating-bananas")
                request = fetch.call_args.args[0]
                self.assertEqual(json.loads(request.data)["variables"]["titleSlug"], "koko-eating-bananas")
                self.assertEqual(result["difficulty"] if result else None, "Medium" if difficulty == "Medium" else None)

    def test_catalog_fallback_and_single_fetch(self):
        rows = [{"link": "koko-eating-bananas/", "problem": "Koko Eating Bananas",
                 "difficulty": "Medium", "pattern": "Binary Search"}]
        with patch.object(generator, "fetch_leetcode_info", return_value=None), patch.object(
                generator.urllib.request, "urlopen", return_value=io.BytesIO(json.dumps(rows).encode())) as fetch:
            self.assertEqual(generator.fetch_problem_info("eating-bananas")["difficulty"], "Medium")
            self.assertIsNone(generator.fetch_problem_info("unrecognized-problem"))
            fetch.assert_called_once()

    def test_network_failure_does_not_invent_difficulty(self):
        with patch.object(generator.urllib.request, "urlopen", side_effect=OSError("offline")):
            self.assertIsNone(generator.fetch_problem_info("unrecognized-problem"))

    def test_pending_problem_stays_in_catalog_and_total_then_recovers(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            readme = root / "README.md"
            overview = root / "assets/overview.svg"
            metadata = root / "metadata.json"
            with patch.multiple(generator, README_PATH=str(readme), OVERVIEW_PATH=overview,
                                METADATA_PATH=str(metadata)), patch.object(generator, "find_all_problems", return_value=[self.item]), \
                    patch.object(generator, "write_pattern_cards", return_value=""), \
                    patch.object(generator, "fetch_problem_info", side_effect=[None, self.medium]):
                generator.main()
                text = readme.read_text()
                self.assertIn("Browse all 1 solutions", text)
                self.assertIn("Difficulty pending (1 Problems)", text)
                self.assertIn("Easy (0 Problems)", text)
                svg = ET.parse(overview).getroot()
                circles = svg.findall("{http://www.w3.org/2000/svg}circle")
                self.assertEqual(circles[-1].get("stroke"), "#94a3b8")
                self.assertIn("1 awaiting difficulty", overview.read_text())
                generator.main()
                text = readme.read_text()
                self.assertNotIn("Difficulty pending", text)
                self.assertIn("Medium (1 Problems)", text)
                self.assertIn("Browse all 1 solutions", text)
                self.assertEqual(len(list((root / "assets/readme").glob("overview-*.svg"))), 1)
                self.assertEqual(json.loads(metadata.read_text())["eating-bananas"]["difficulty"], "Medium")


if __name__ == "__main__":
    unittest.main()
