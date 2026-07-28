# 344. Reverse String

**Link:** https://leetcode.com/problems/reverse-string/
**Difficulty:** Easy
**Approach:** Two Pointers (in-place swap)
**Time:** O(n)   **Space:** O(1)

## Problem

Reverse a string given as a character array `s`, **in-place** —
without allocating a second array. `s` is modified directly and
nothing is returned.

## Idea

Use two pointers:
- `left` starts at index `0` (first character)
- `right` starts at index `s.size() - 1` (last character)

Repeatedly:
1. Swap `s[left]` and `s[right]`.
2. Move `left` forward one step, `right` backward one step.
3. Stop once `left >= right` (the pointers have met or crossed —
   every pair has been swapped).

For an odd-length array, the middle element never needs a partner
swap — it's naturally skipped since the loop stops as soon as
`left` is no longer strictly less than `right`.

### Why a temp variable is needed for the swap

```cpp
s[left] = s[right];   // overwrites s[left] — its original value is now lost
s[right] = s[left];   // this just copies s[right]'s value back onto itself — wrong!
```

Without a temporary variable, the first line destroys `s[left]`'s
original value before it can be written into `s[right]`. The fix is
to save it first:

```cpp
char temp = s[left];   // save s[left] before it gets overwritten
s[left] = s[right];    // now safe to overwrite
s[right] = temp;        // write the ORIGINAL s[left] value into s[right]
```

## Code

```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;

            left++;
            right--;
        }
    }
};
```

## Step-by-Step Trace

```
s = ['h','e','l','l','o']    left=0, right=4

Iter 1: swap s[0],s[4] -> o e l l h    left=1, right=3
Iter 2: swap s[1],s[3] -> o l l e h    left=2, right=2
Check: left < right? 2 < 2 -> false, stop

Result: ['o','l','l','e','h']
```

Even-length check:
```
s = ['a','b','c','d']    left=0, right=3

Iter 1: swap s[0],s[3] -> d b c a    left=1, right=2
Iter 2: swap s[1],s[2] -> d c b a    left=2, right=1
Check: left < right? 2 < 1 -> false, stop

Result: ['d','c','b','a']
```

## Key Insights

- This is passed as `vector<char>&` — a reference, not a copy — so
  the swaps inside the function actually modify the caller's array.
  Without the `&`, the function would only reverse a throwaway copy
  and the original array would remain unchanged.
- `left < right` (strict) is the correct stop condition, not
  `left <= right` — it naturally handles odd-length arrays by
  leaving the untouched middle element in place.
- Swapping two values always needs a third temporary variable to
  avoid overwriting data before it's been read.

## Complexity

- **Time:** O(n) — each element is visited once as the two pointers
  move toward the middle (n/2 swaps total).
- **Space:** O(1) — only `left`, `right`, and `temp` are used; no
  extra array is allocated.
