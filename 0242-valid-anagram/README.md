# 242. Valid Anagram

**Link:** https://leetcode.com/problems/valid-anagram/
**Difficulty:** Easy
**Approach:** Hash Map (unordered_map) — balance counts to zero
**Time:** O(n)   **Space:** O(1) (bounded by alphabet size, not input length)

## Problem

Given two strings `s` and `t`, return `true` if `t` is an anagram of
`s` — meaning both strings use exactly the same characters, the same
number of times, just possibly rearranged.

## Idea

1. **Free check first:** if `s` and `t` have different lengths, they
   can't possibly be anagrams — return `false` immediately, no need
   to look at characters at all.
2. Use a **single** `unordered_map<char, int>` as a running balance:
   - Walk through `s`, incrementing each character's count.
   - Walk through `t`, decrementing each character's count in the
     *same* map.
3. If `s` and `t` are true anagrams, every character's count should
   net out to exactly `0`. Scan the map — if any value is nonzero,
   they're not anagrams.

Using one shared map instead of two separate maps avoids having to
compare keys across two different maps at the end — a single scan
for "is everything zero?" is enough.

## Code

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char, int> count;

        for (int i = 0; i < s.size(); i++) {
            count[s[i]]++;
        }

        for (int i = 0; i < t.size(); i++) {
            count[t[i]]--;
        }

        for (auto p : count) {
            if (p.second != 0) {
                return false;
            }
        }

        return true;
    }
};
```

## Step-by-Step Trace

```
s = "anagram", t = "nagaram"

Length check: both 7 -> passes

Counting up through s:
a:3, n:1, g:1, r:1, m:1

Counting down through t:
n-1, a-1, g-1, a-1, r-1, a-1, m-1
-> every character's count returns to 0

Final scan: all values are 0 -> return true
```

```
s = "rat", t = "car"

Length check: both 3 -> passes

Counting up through s: r:1, a:1, t:1
Counting down through t: c:-1, a:0, r:0

Final map: {r:0, a:0, t:1, c:-1}
t is 1, not 0 -> return false
```

## Key Insights

- Checking character **presence** alone isn't enough — anagrams
  require matching **counts** too (e.g. "aab" vs "abb" share the
  same letters but aren't anagrams).
- The "count up / count down, check for zero" trick is a common
  pattern for comparing two collections without needing two
  separate data structures.
- `count[s[i]]++` and `count[t[i]]--` both rely on the map's
  auto-insert-with-default-0 behavior, same as in Majority Element.

## Complexity

- **Time:** O(n) where n is the length of the strings — three linear
  passes (length check is O(1), then two O(n) loops, then a scan
  over the map bounded by alphabet size).
- **Space:** O(1) in practice, since the map holds at most one entry
  per distinct character (bounded by the alphabet, not input size).
