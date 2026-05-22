# Count It

## Description

This project implements a Python script that queries the Reddit API recursively to fetch all hot articles from a given subreddit, parses their titles, and prints a sorted count of specified keywords.

The script is case-insensitive and uses recursion to handle pagination through the Reddit API to retrieve all hot posts.

## Problem Statement

Given a subreddit name and a list of keywords, the script should:

1. **Query the Reddit API** for hot posts in the specified subreddit
2. **Parse article titles** to extract words
3. **Count occurrences** of specified keywords (case-insensitive)
4. **Handle pagination** recursively to retrieve all available hot posts
5. **Apply weights** if a keyword appears multiple times in the word list
6. **Display results** sorted by count (descending) and alphabetically (ascending)

## Algorithm Explanation

### Key Features

1. **Recursive API Pagination**
   - Uses the `after` parameter to paginate through Reddit's API
   - Fetches up to 100 posts per request
   - Recursively calls itself for subsequent pages

2. **Word Extraction**
   - Converts titles to lowercase for case-insensitive comparison
   - Splits titles by non-alphanumeric characters
   - Only counts words that match the provided keyword list

3. **Weight System**
   - If a keyword appears multiple times in the input list, it gets multiplied weight
   - Example: `['python', 'python']` counts each occurrence twice

4. **Sorting**
   - Primary: Sort by count (descending)
   - Secondary: Sort by word alphabetically (ascending)

### Algorithm Flow

```
1. Normalize word_list (lowercase, calculate weights)
2. Initialize raw_count dictionary
3. Call fetch_hot_posts(subreddit)
   a. Build Reddit API URL with proper headers
   b. Fetch hot posts (limit 100 per request)
   c. Parse each post title
   d. Extract words (split by non-alphanumeric chars)
   e. Count matching keywords
   f. If 'after' token exists, recursively fetch next page
4. Apply weights to raw counts
5. Sort results (count desc, word asc)
6. Print formatted output
```

## Function Signature

```python
def count_words(subreddit, word_list):
    """
    Queries the Reddit API recursively, parses hot article titles,
    and prints a sorted count of keywords (case-insensitive).
    
    Args:
        subreddit (str): Name of the subreddit to query
        word_list (list): List of keywords to count
    
    Returns:
        None (prints results to stdout)
    """
```

## Requirements

- Python 3.x
- `requests` library for HTTP requests

### Installation

```bash
pip install requests
```

## Usage

```python
from 0-count import count_words

# Example: Count Python-related keywords in r/python
count_words("python", ["python", "programming", "code"])

# Example: Count technology keywords in r/technology
count_words("technology", ["tech", "AI", "software", "tech"])
```

### Expected Output Format

```
keyword1: count1
keyword2: count2
keyword3: count3
```

Results are sorted by count in descending order, then alphabetically by keyword.

## Examples

### Example 1: Basic Usage

```python
count_words("programming", ["python", "java", "c"])
```

Output:
```
python: 45
java: 32
c: 28
```

### Example 2: Weighted Keywords

```python
count_words("programming", ["python", "python", "java"])
```

Output:
```
python: 90  # Count multiplied by 2 since "python" appears twice in word_list
java: 32
```

### Example 3: Case Insensitivity

```python
count_words("AskReddit", ["Python", "JAVA", "code"])
```

The function will still find lowercase versions of "python", "java", and "code" in titles.

## Time & Space Complexity

| Aspect | Complexity |
|--------|-----------|
| Time | O(n × m) where n = number of posts fetched, m = average words per title |
| Space | O(k) where k = number of unique keywords matched |

## Files

- `0-count.py` - Main implementation
- `README.md` - This documentation file

## Error Handling

The script handles the following errors gracefully:

- **Invalid subreddit**: Returns silently (no error raised)
- **Network errors**: Returns silently
- **HTTP status errors**: Checks for status code 200, returns silently otherwise
- **JSON parsing errors**: Returns silently

## Important Notes

- The script uses proper User-Agent headers as required by Reddit's API
- `allow_redirects=False` is used to catch invalid subreddit redirects
- Words are extracted by splitting on non-alphanumeric characters
- If no keywords match any titles, nothing is printed
- The script doesn't require authentication (uses public API)

## Reddit API Endpoint

- **Base URL**: `https://www.reddit.com/r/{subreddit}/hot.json`
- **Parameters**: 
  - `limit`: Number of posts per request (max 100)
  - `after`: Token for pagination to get next batch

## Limitations

- Limited to hot posts only (not new, top, etc.)
- Depends on Reddit API availability
- Rate limited by Reddit's API
- Only fetches posts available through the hot endpoint

## Author

Interview Preparation - Web Scraping & API Series

## Resources

- [Reddit API Documentation](https://www.reddit.com/dev/api)
- [Python Requests Library](https://requests.readthedocs.io/)
- [Web Scraping Best Practices](https://www.geeksforgeeks.org/web-scraping-with-python/)
