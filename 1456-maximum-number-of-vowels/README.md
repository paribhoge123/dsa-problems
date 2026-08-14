# 1456. Maximum Number of Vowels in a Substring of Given Length

**Link:** https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
**Difficulty:** Medium
**Approach:** Sliding Window (fixed size) + Hash Set for vowel check
**Time:** O(n)   **Space:** O(1) (vowel set is always size 5)

## Problem

Given a string `s` and integer `k`, return the maximum number of
vowels (`a, e, i, o, u`) in any substring of length `k`.

## Idea

Same fixed-size sliding window skeleton as Maximum Average Subarray,
just swap "sum of numbers" for "count of vowels":

- **Phase 1:** Count vowels in the first `k` characters.
- **Phase 2:** Slide the window one step at a time. When a new
  character enters (at `s[i]`), check if it's a vowel — if so,
  `count++`. When the old character leaves (at `s[i-k]`), check if
  it was a vowel — if so, `count--`. Track the max count seen.

To check if a character is a vowel, use an `unordered_set<char>`
containing the five vowels — `.count(c)` returns `1` if it's a
vowel, `0` if not. This avoids writing five separate `==` checks.

The key distinction: you're adding/subtracting `1` (not the
character's value) based on whether the character is a vowel. `count`
tracks how many vowels are currently inside the window, not any sum
of character values.

## Code

```cpp
class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowels = {'a','e','i','o','u'};

        int count = 0;
        for (int i = 0; i < k; i++) {
            if (vowels.count(s[i])) count++;
        }

        int maxCount = count;

        for (int i = k; i < s.size(); i++) {
            if (vowels.count(s[i]))   count++;
            if (vowels.count(s[i-k])) count--;
            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};
```

## Step-by-Step Trace

```
s = "abciiidef", k=3

Phase 1:
s[0]='a' -> vowel -> count=1
s[1]='b' -> not vowel
s[2]='c' -> not vowel
count=1, maxCount=1

Phase 2:
i=3: 'i' enters(+1), 'a' leaves(-1) -> count=1, maxCount=1
i=4: 'i' enters(+1), 'b' leaves(0)  -> count=2, maxCount=2
i=5: 'i' enters(+1), 'c' leaves(0)  -> count=3, maxCount=3
i=6: 'd' enters(0),  'i' leaves(-1) -> count=2, maxCount=3
i=7: 'e' enters(+1), 'i' leaves(-1) -> count=2, maxCount=3
i=8: 'f' enters(0),  'i' leaves(-1) -> count=1, maxCount=3

Result: 3
```

## Key Insights

- The entering character is at `s[i]`, the leaving character is at
  `s[i-k]` — when the right edge of a window of size `k` is at `i`,
  the left edge is always exactly `k` steps behind at `i-k`.
- `count += s[i]` would add the ASCII value of the character (wrong).
  The correct pattern is `if (vowels.count(s[i])) count++` — add `1`
  only when the character qualifies, not its numeric value.
- The sliding window skeleton (build first window, then slide with
  add-one/remove-one) is identical across fixed-size window problems —
  only what you're counting changes.

## Complexity

- **Time:** O(n) — one O(k) pass for Phase 1, one O(n) pass for
  Phase 2. Each set lookup is O(1).
- **Space:** O(1) — the vowel set always has exactly 5 entries
  regardless of input size.
