#!/usr/bin/env python3
import os
import json
import re
import urllib.request
import urllib.error

REPO_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", ".."))
DSA_DIR = os.path.join(REPO_ROOT, "Data Structures & Algorithms")
README_PATH = os.path.join(REPO_ROOT, "README.md")
METADATA_PATH = os.path.join(os.path.dirname(__file__), "problems_metadata.json")

# Known NeetCode -> LeetCode slug mappings
NEETCODE_ALIASES = {
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
