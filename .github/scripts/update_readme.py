#!/usr/bin/env python3
import os
import json
import re
import urllib.request
import urllib.error
import math
from pathlib import Path

REPO_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", ".."))
DSA_DIR = os.path.join(REPO_ROOT, "Data Structures & Algorithms")
README_PATH = os.path.join(REPO_ROOT, "README.md")
METADATA_PATH = os.path.join(os.path.dirname(__file__), "problems_metadata.json")
OVERVIEW_PATH = Path(REPO_ROOT) / "assets" / "overview.svg"


def write_overview(easy, medium, hard):
    """Render the GitHub-friendly overview from the catalog counts."""
    total = easy + medium + hard
    counts = [("Easy", easy, "#36b782"), ("Medium", medium, "#e5ae46"),
              ("Hard", hard, "#ef6b73")]
    largest = max(easy, medium, hard, 1)
    bars = []
    for index, (label, count, color) in enumerate(counts):
        y = 218 + index * 37
        width = 228 * count / largest
        bars.append(
            f'<text x="54" y="{y}" class="label">{label}</text>'
            f'<rect x="125" y="{y - 11}" width="228" height="9" rx="4.5" fill="#30363d"/>'
            f'<rect x="125" y="{y - 11}" width="{width:.2f}" height="9" rx="4.5" fill="{color}"/>'
            f'<text x="388" y="{y}" class="count" text-anchor="end">{count}</text>'
        )

    segments = []
    circumference = 2 * math.pi * 82
    offset = 0
    for _, count, color in counts:
        if count:
            length = circumference * count / total
            segments.append(
                f'<circle cx="705" cy="181" r="82" fill="none" stroke="{color}" '
                f'stroke-width="20" stroke-dasharray="{length:.4f} {circumference - length:.4f}" '
                f'stroke-dashoffset="{-offset:.4f}" transform="rotate(-90 705 181)"/>'
            )
            offset += length

    easy_share = round(100 * easy / total) if total else 0
    svg = f'''<svg xmlns="http://www.w3.org/2000/svg" width="900" height="350" viewBox="0 0 900 350" role="img" aria-labelledby="title desc">
<title id="title">Problem Solving overview</title>
<desc id="desc">{total} problems solved: {easy} easy, {medium} medium, and {hard} hard.</desc>
<style>
text {{ font-family: -apple-system, BlinkMacSystemFont, "Segoe UI", sans-serif; }}
.eyebrow {{ fill: #b998f4; font-size: 13px; font-weight: 700; letter-spacing: 2px; }}
.total {{ fill: #f0f6fc; font-size: 76px; font-weight: 750; letter-spacing: -4px; }}
.subtitle {{ fill: #9ca3af; font-size: 17px; }}
.label {{ fill: #c9d1d9; font-size: 15px; font-weight: 600; }}
.count {{ fill: #f0f6fc; font-size: 15px; font-weight: 700; }}
.percentage {{ fill: #f0f6fc; font-size: 36px; font-weight: 750; }}
.ring-label {{ fill: #9ca3af; font-size: 14px; }}
</style>
<rect x="1" y="1" width="898" height="348" rx="16" fill="#0d1117" stroke="#30363d"/>
<rect x="1" y="1" width="5" height="348" rx="2.5" fill="#8b5bd5"/>
<text x="54" y="51" class="eyebrow">PROBLEM SOLVING / OVERVIEW</text>
<text x="50" y="139" class="total">{total}</text>
<text x="54" y="168" class="subtitle">problems solved</text>
{''.join(bars)}
<circle cx="705" cy="181" r="82" fill="none" stroke="#30363d" stroke-width="20"/>
{''.join(segments)}
<text x="705" y="180" class="percentage" text-anchor="middle">{easy_share}%</text>
<text x="705" y="204" class="ring-label" text-anchor="middle">easy</text>
<text x="705" y="314" class="subtitle" text-anchor="middle">Difficulty mix</text>
</svg>
'''
    OVERVIEW_PATH.parent.mkdir(parents=True, exist_ok=True)
    OVERVIEW_PATH.write_text(svg, encoding="utf-8")

# Known NeetCode -> LeetCode slug mappings
NEETCODE_ALIASES = {
    "top-k-elements-in-list": "top-k-frequent-elements",
    "duplicate-integer": "contains-duplicate",
    "is-anagram": "valid-anagram",
    "two-integer-sum": "two-sum",
    "two-integer-sum-ii": "two-sum-ii-input-array-is-sorted",
    "is-palindrome": "valid-palindrome",
    "minimum-stack": "min-stack",
    "validate-parentheses": "valid-parentheses",
    "reverse-a-linked-list": "reverse-linked-list",
    "merge-two-sorted-linked-lists": "merge-two-sorted-lists",
    "reorder-linked-list": "reorder-list",
    "remove-node-from-end-of-linked-list": "remove-nth-node-from-end-of-list",
    "copy-linked-list-with-random-pointer": "copy-list-with-random-pointer",
    "find-duplicate-integer": "find-the-duplicate-number",
    "invert-a-binary-tree": "invert-binary-tree",
    "maximum-depth-of-binary-tree": "maximum-depth-of-binary-tree",
    "diameter-of-binary-tree": "diameter-of-binary-tree",
    "balanced-binary-tree": "balanced-binary-tree",
    "same-binary-tree": "same-tree",
    "subtree-of-a-binary-tree": "subtree-of-another-tree",
    "lowest-common-ancestor-in-binary-search-tree": "lowest-common-ancestor-of-a-binary-search-tree",
    "valid-binary-search-tree": "validate-binary-search-tree",
    "binary-tree-level-order-traversal": "binary-tree-level-order-traversal",
    "binary-tree-right-side-view": "binary-tree-right-side-view",
    "count-good-nodes-in-binary-tree": "count-good-nodes-in-binary-tree",
    "kth-smallest-element-in-a-bst": "kth-smallest-element-in-a-bst",
    "construct-binary-tree-from-preorder-and-inorder-traversal": "construct-binary-tree-from-preorder-and-inorder-traversal",
    "binary-tree-maximum-path-sum": "binary-tree-maximum-path-sum",
    "serialize-and-deserialize-binary-tree": "serialize-and-deserialize-binary-tree"
}

def load_metadata():
    if os.path.exists(METADATA_PATH):
        try:
            with open(METADATA_PATH, "r", encoding="utf-8") as f:
                return json.load(f)
        except Exception as e:
            print(f"Warning: Could not read metadata file: {e}")
    return {}

def save_metadata(meta):
    try:
        with open(METADATA_PATH, "w", encoding="utf-8") as f:
            json.dump(meta, f, indent=2, ensure_ascii=False)
            f.write("\n")
    except Exception as e:
        print(f"Warning: Could not save metadata file: {e}")

def fetch_leetcode_info(slug):
    leetcode_slug = NEETCODE_ALIASES.get(slug, slug)
    query = """
    query getQuestionDetail($titleSlug: String!) {
      question(titleSlug: $titleSlug) {
        title
        difficulty
        topicTags {
          name
        }
      }
    }
    """
    url = "https://leetcode.com/graphql"
    data = json.dumps({"query": query, "variables": {"titleSlug": leetcode_slug}}).encode("utf-8")
    req = urllib.request.Request(
        url,
        data=data,
        headers={
            "Content-Type": "application/json",
            "User-Agent": "Mozilla/5.0 (GitHubAction-ProblemTracer)"
        }
    )
    try:
        with urllib.request.urlopen(req, timeout=5) as response:
            payload = json.loads(response.read().decode("utf-8"))
            q = payload.get("data", {}).get("question")
            if q:
                title = q.get("title")
                diff = q.get("difficulty", "Medium")
                tags = [t["name"] for t in q.get("topicTags", [])[:2]]
                cat = " / ".join(tags) if tags else "Algorithms"
                return {"title": title, "difficulty": diff, "category": cat}
    except Exception as e:
        print(f"Notice: Could not fetch info from LeetCode for {slug}: {e}")
    return None

def slug_to_title(slug):
    parts = slug.split("-")
    roman_numerals = {"i": "I", "ii": "II", "iii": "III", "iv": "IV", "v": "V"}
    return " ".join([roman_numerals.get(p.lower(), p.capitalize()) for p in parts])

def find_dsa_solution_file(prob_dir):
    if not os.path.exists(prob_dir):
        return None
    files = sorted([f for f in os.listdir(prob_dir) if f.startswith("submission-") and not f.startswith(".")])
    if files:
        return files[-1]  # latest submission
    code_files = sorted([f for f in os.listdir(prob_dir) if f.endswith((".cpp", ".py", ".java", ".ts", ".js", ".cs", ".go", ".rs"))])
    if code_files:
        return code_files[0]
    return None

def find_all_problems():
    problems = []

    # 1. Scan Data Structures & Algorithms
    if os.path.exists(DSA_DIR):
        for d in sorted(os.listdir(DSA_DIR)):
            prob_dir = os.path.join(DSA_DIR, d)
            if os.path.isdir(prob_dir) and not d.startswith("."):
                sol_file = find_dsa_solution_file(prob_dir)
                rel_folder = f"Data Structures & Algorithms/{d}"
                rel_sol = f"{rel_folder}/{sol_file}" if sol_file else None
                problems.append({
                    "slug": d,
                    "folder_relpath": rel_folder,
                    "sol_relpath": rel_sol,
                    "source": "DSA"
                })

    # 2. Scan LeetBridge / Root problem folders (e.g. 0001-two-sum)
    for d in sorted(os.listdir(REPO_ROOT)):
        prob_dir = os.path.join(REPO_ROOT, d)
        if not os.path.isdir(prob_dir) or d.startswith("."):
            continue
        if d in ["Data Structures & Algorithms"]:
            continue

        is_leetbridge = bool(re.match(r"^\d{4}-", d))
        readme_path = os.path.join(prob_dir, "README.md")
        has_readme = os.path.exists(readme_path)

        if is_leetbridge or (has_readme and any(f.startswith("solution.") for f in os.listdir(prob_dir))):
            slug = re.sub(r"^\d+-", "", d)
            sol_files = sorted([f for f in os.listdir(prob_dir) if f.startswith("solution.")])
            sol_file = sol_files[0] if sol_files else None
            rel_sol = f"{d}/{sol_file}" if sol_file else None

            readme_title = None
            readme_diff = None
            if has_readme:
                try:
                    with open(readme_path, "r", encoding="utf-8") as rf:
                        txt = rf.read()
                        m_title = re.search(r"^#\s+(?:\d+\.\s*)?([^\n\r]+)", txt, re.MULTILINE)
                        if m_title:
                            readme_title = m_title.group(1).strip()
                        m_diff = re.search(r"\*\*Difficulty:\*\*\s*([A-Za-z]+)", txt)
                        if m_diff:
                            readme_diff = m_diff.group(1).strip()
                except Exception:
                    pass

            problems.append({
                "slug": slug,
                "folder_relpath": d,
                "sol_relpath": rel_sol,
                "readme_title": readme_title,
                "readme_diff": readme_diff,
                "source": "LeetCode"
            })

    return problems

def main():
    metadata = load_metadata()
    updated_meta = False

    problems = find_all_problems()
    print(f"Total problems discovered across repository: {len(problems)}")

    problems_by_diff = {"Easy": [], "Medium": [], "Hard": []}

    for item in problems:
        slug = item["slug"]
        meta = metadata.get(slug)
        if not meta:
            fetched = fetch_leetcode_info(slug)
            if fetched:
                meta = fetched
            else:
                title = item.get("readme_title") or slug_to_title(slug)
                diff = item.get("readme_diff") or "Easy"
                meta = {
                    "title": title,
                    "difficulty": diff,
                    "category": "Algorithms"
                }
            metadata[slug] = meta
            updated_meta = True

        diff = (item.get("readme_diff") or meta.get("difficulty", "Easy")).capitalize()
        if diff not in problems_by_diff:
            problems_by_diff[diff] = []

        title = item.get("readme_title") or meta.get("title", slug_to_title(slug))
        category = meta.get("category", "Algorithms")

        problems_by_diff[diff].append({
            "slug": slug,
            "title": title,
            "category": category,
            "folder_relpath": item["folder_relpath"],
            "sol_relpath": item["sol_relpath"]
        })

    if updated_meta:
        save_metadata(metadata)

    # Sort each list alphabetically by problem title
    for diff in problems_by_diff:
        problems_by_diff[diff].sort(key=lambda x: x["title"].lower())

    easy_count = len(problems_by_diff.get("Easy", []))
    medium_count = len(problems_by_diff.get("Medium", []))
    hard_count = len(problems_by_diff.get("Hard", []))
    total_count = easy_count + medium_count + hard_count
    write_overview(easy_count, medium_count, hard_count)

    # Build markdown section
    lines = [
        "---",
        "",
        "## Solved Problems Catalog",
        "",
        "Curated list of all algorithmic and data structure problems solved and tracked across LeetCode and NeetCode, categorized by difficulty level.",
        "",
        "### Difficulty Overview",
        "| Level | Count |",
        "| :--- | :---: |",
        f"| 🟢 **Easy** | {easy_count} |",
        f"| 🟡 **Medium** | {medium_count} |",
        f"| 🔴 **Hard** | {hard_count} |",
        f"| **Total** | **{total_count}** |",
        ""
    ]

    def render_table(diff_label, emoji, problem_items):
        table_lines = [
            "---",
            "",
            f'<a id="{diff_label.lower()}"></a>',
            "",
            f"### {emoji} {diff_label} ({len(problem_items)} Problems)",
            "",
            "| # | Problem | Category / Pattern | Solution |",
            "| :-: | :--- | :--- | :-: |"
        ]
        for idx, it in enumerate(problem_items, 1):
            prob_link = f"[{it['title']}](<{it['folder_relpath']}>)"
            if it["sol_relpath"]:
                ext = os.path.splitext(it["sol_relpath"])[1]
                lang = "C++" if ext == ".cpp" else "Python" if ext == ".py" else "Code"
                sol_link = f"[{lang}](<{it['sol_relpath']}>)"
            else:
                sol_link = f"[Folder](<{it['folder_relpath']}>)"
            table_lines.append(f"| {idx} | {prob_link} | {it['category']} | {sol_link} |")
        table_lines.append("")
        return table_lines

    lines.extend(render_table("Easy", "🟢", problems_by_diff.get("Easy", [])))
    lines.extend(render_table("Medium", "🟡", problems_by_diff.get("Medium", [])))
    if hard_count > 0:
        lines.extend(render_table("Hard", "🔴", problems_by_diff.get("Hard", [])))

    new_section = "\n".join(lines).strip() + "\n"

    # Read existing README.md
    if os.path.exists(README_PATH):
        with open(README_PATH, "r", encoding="utf-8") as f:
            content = f.read()
    else:
        content = "# Problem Solving\n\n"

    marker = "<!-- SOLUTIONS_END -->"
    if marker in content:
        top_part = content.split(marker)[0] + marker + "\n\n"
        final_content = top_part + new_section
    elif "## Solved Problems Catalog" in content:
        top_part = content.split("## Solved Problems Catalog")[0]
        final_content = top_part + new_section
    elif "## Data Structures & Algorithms" in content:
        top_part = content.split("## Data Structures & Algorithms")[0]
        final_content = top_part + new_section
    else:
        final_content = content.rstrip() + "\n\n" + new_section

    with open(README_PATH, "w", encoding="utf-8") as f:
        f.write(final_content)

    print("README.md successfully updated!")

if __name__ == "__main__":
    main()
