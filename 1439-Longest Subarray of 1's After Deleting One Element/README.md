# LeetCode 1493 — Longest Subarray of 1's After Deleting One Element

## Problem

Given a binary array `nums`, find the longest subarray containing only `1`s after deleting **exactly one element**.

### Example

```text
Input:
nums = [1,1,0,1]

Output:
3
```

Delete the `0`:

```text
[1,1,0,1]
      ↓
[1,1,1]
```

So the answer is `3`.

---

## Approach — Sliding Window + Two Pointers

The key observation is:

> Since we can delete exactly one element, our window can contain **at most one `0`**.

For example:

```text
[1, 1, 0, 1, 1]
```

We can delete the `0` and get:

```text
[1, 1, 1, 1]
```

So instead of directly deciding which element to delete, we find the **longest window containing at most one zero**.

### Two Pointers

Use:

* `left` → beginning of the window
* `right` → end of the window
* `zeros` → number of zeros inside the current window

---

## Algorithm

1. Start `left` at `0`.
2. Move `right` through the array.
3. If `nums[right] == 0`, increase `zeros`.
4. If `zeros > 1`, shrink the window from the left.
5. When the window is valid, update the answer.
6. Use `right - left` instead of the normal window size because **one element must be deleted**.

---

## Why `right - left`?

Normally, the window size is:

```text
right - left + 1
```

But we must delete exactly one element:

```text
(right - left + 1) - 1
= right - left
```

Therefore:

```cpp
ans = max(ans, right - left);
```

---

## C++ Solution

```cpp
class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int left = 0;
        int zeros = 0;
        int ans = 0;

        for (int right = 0; right < nums.size(); right++) {

            // Add current element to the window
            if (nums[right] == 0) {
                zeros++;
            }

            // More than one zero → shrink window
            while (zeros > 1) {
                if (nums[left] == 0) {
                    zeros--;
                }

                left++;
            }

            // One element must be deleted
            ans = max(ans, right - left);
        }

        return ans;
    }
};
```

---

## Dry Run

```text
nums = [1,1,0,1]
```

| `right` | Current Window | `zeros` | Valid? | `right - left` |
| ------: | -------------- | ------: | ------ | -------------: |
|       0 | `[1]`          |       0 | Yes    |              0 |
|       1 | `[1,1]`        |       0 | Yes    |              1 |
|       2 | `[1,1,0]`      |       1 | Yes    |              2 |
|       3 | `[1,1,0,1]`    |       1 | Yes    |              3 |

Delete the `0` from the final window:

```text
[1,1,0,1]
     ↓
[1,1,1]
```

Answer:

```text
3
```

---

## Complexity

### Time

`O(n)`

Both `left` and `right` only move forward through the array.

### Space

`O(1)`

Only a few variables are used.

---

## Key Pattern

### Sliding Window with At Most One Zero

```text
Expand window
      ↓
Count zeros
      ↓
zeros > 1 ?
   ↙       ↘
 Yes        No
  ↓          ↓
Shrink     Update
window     answer
```

### Important Formula

```cpp
ans = max(ans, right - left);
```

The `-1` is already represented by using `right - left`, because exactly one element must be deleted.

---

## What to Remember

The most important insight is:

> **"I can delete one element" → "I can allow one zero in my sliding window."**

This transforms the problem into a standard **Sliding Window + Two Pointers** problem.

### Pattern to recognize in future problems

If a problem says something like:

* longest subarray
* after deleting/removing something
* at most `k` bad elements

Think:

**Sliding Window + Two Pointers.**
