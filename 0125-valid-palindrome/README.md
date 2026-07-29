# 125. Valid Palindrome

**Link:** https://leetcode.com/problems/valid-palindrome/
**Difficulty:** Easy
**Approach:** Two Pointers (compare instead of swap)
**Time:** O(n)   **Space:** O(1)

## Problem

Given a string `s`, return `true` if it's a palindrome after:
- ignoring all non-alphanumeric characters (spaces, punctuation, etc.)
- ignoring case (`'A'` and `'a'` count as the same character)

## Idea

Reuses the same two-pointer skeleton from Reverse String — `left`
starts at index `0`, `right` starts at the last index, moving toward
each other. The difference: instead of swapping, we **compare**.

Two new pieces are needed:

1. **Skip characters that don't count.** Before comparing, skip
   forward past any non-alphanumeric character at `left`, and skip
   backward past any non-alphanumeric character at `right`. This
   uses `isalnum(c)`, which returns `true` only for letters and
   digits.
2. **Ignore case when comparing.** Convert both characters to
   lowercase before comparing, using `tolower(c)`.

If at any point the two (cleaned, lowercased) characters don't
match, it's not a palindrome — return `false` immediately. If the
pointers meet without ever mismatching, it is a palindrome.

## Code

```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            // skip non-alphanumeric characters from the left
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            // skip non-alphanumeric characters from the right
            while (left < right && !isalnum(s[right])) {
                right--;
            }

            // compare characters, ignoring case
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};
```

## Step-by-Step Trace

```
s = "A man, a plan, a canal: Panama"

left=0 ('A'), right=30 ('a') -> both alnum, tolower match ('a'=='a') -> left=1, right=29
left=1 (' '), not alnum -> skip -> left=2 ('m')
right=29 ('m'), alnum -> compare 'm' == 'm' -> left=3, right=28
... continues skipping spaces/punctuation and matching letters ...
pointers meet without any mismatch -> return true
```

```
s = "race a car"

left=0 ('r'), right=9 ('r') -> match -> left=1, right=8
left=1 ('a'), right=8 ('a') -> match -> left=2, right=7
left=2 ('c'), right=7 ('c') -> match -> left=3, right=6
left=3 ('e'), right=6 (' ') -> not alnum -> skip right -> right=5 ('a')
compare 'e' vs 'a' -> MISMATCH -> return false
```

## Key Insights

- The inner `while` loops that skip non-alphanumeric characters also
  check `left < right` — without that guard, `left` or `right` could
  run past each other (or out of bounds) while skipping through a
  string that's entirely punctuation/spaces.
- `isalnum` and `tolower` are small built-in helpers worth knowing —
  they save writing manual character-range checks (e.g. checking
  `'a' <= c <= 'z'` by hand).
- Same core two-pointer shape as Reverse String, just swapping the
  "swap" action for a "compare and skip" action — a good example of
  how one pattern (converge from both ends) supports different jobs.

## Complexity

- **Time:** O(n) — each character is visited at most once as the
  pointers converge, including the skip steps.
- **Space:** O(1) — only `left` and `right` are used, no extra
  string or array is built.
