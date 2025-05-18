#!/usr/bin/python3
"""
Recursive function to query Reddit API and count keyword occurrences
in the titles of hot articles.
"""

import requests


def count_words(subreddit, word_list, after=None, word_count={}):
    """
    Recursively queries Reddit API, parses titles of hot articles,
    and prints a sorted count of given keywords (case-insensitive).
    """
    if after is None:
        # Initialize word count dictionary
        # (case-insensitive, include duplicates)
        word_count = {}
        for word in word_list:
            w = word.lower()
            word_count[w] = word_count.get(w, 0)

    url = f"https://www.reddit.com/r/{subreddit}/hot.json"
    headers = {'User-Agent': 'custom'}
    params = {'limit': 100, 'after': after}

    try:
        response = requests.get(
            url, headers=headers, params=params, allow_redirects=False
        )
        if response.status_code != 200:
            return
        data = response.json().get("data", {})
        posts = data.get("children", [])
        for post in posts:
            title = post["data"]["title"].lower().split()
            for word in word_count.keys():
                word_count[word] += title.count(word)

        after = data.get("after")
        if after:
            return count_words(subreddit, word_list, after, word_count)

        # Print results sorted by count desc, then alphabetically
        sorted_words = sorted(
            [(k, v) for k, v in word_count.items() if v > 0],
            key=lambda item: (-item[1], item[0])
        )
        for word, count in sorted_words:
            print(f"{word}: {count}")

    except Exception:
        return
