# 209. Minimum Size Subarray Sum

**Link:** https://leetcode.com/problems/minimum-size-subarray-sum/
**Difficulty:** Medium
**Approach:** Sliding Window (variable size)
**Time:** O(n)   **Space:** O(1)

## Problem

Given an array of positive integers `nums` and a positive integer
`target`, return the minimum length of a subarray whose sum is
>= `target`. Return `0` if no such subarray exists.

## Idea

Unlike fixed-size sliding window problems, the window size here is
unknown — it needs to be found. The window grows and shrinks
dynamically based on whether the current sum meets the target.

Think of it like a rubber band:
- **Stretch right** (`right++`): keep adding elements until the sum
  hits the target.
- **Shrink left** (`left++`): once the sum meets the target, try
  making the window smaller while still staying valid. Record the
  window size before each shrink.
- Track the **minimum** length of any valid window seen.

Two pointers (`left` and `right`) both start at `0` and only ever
move forward — so each element is added and removed at most once,
keeping the whole algorithm O(n) despite the nested `while` loop.

`INT_MAX` is used as the starting `minLen` so any real window
length will beat it on the first valid window found.

## Code

```cpp
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int windowSum = 0;
        int minLen = INT_MAX;

        for (int right = 0; right < nums.size(); right++) {
            windowSum += nums[right];

            while (windowSum >= target) {
                minLen = min(minLen, right - left + 1);
                windowSum -= nums[left];
                left++;
            }
        }

        return minLen == INT_MAX ? 0 : minLen;
    }
};
```

## Step-by-Step Trace

```
nums = [2,3,1,2,4,3], target=7

right=0: sum=2  < 7
right=1: sum=5  < 7
right=2: sum=6  < 7
right=3: sum=8 >= 7 -> minLen=min(MAX,4)=4, sum=6, left=1
right=4: sum=10 >= 7 -> minLen=min(4,4)=4, sum=7, left=2
              still >= 7 -> minLen=min(4,3)=3, sum=6, left=3
right=5: sum=9  >= 7 -> minLen=min(3,3)=3, sum=7, left=4
              still >= 7 -> minLen=min(3,2)=2, sum=3, left=5

Result: 2
```

## Key Insights

- `minLen` must be updated **before** shrinking — once you shrink,
  the window that met the condition is gone. Record it first, then
  remove the left element.
- `right - left + 1` is the current window size — both ends are
  inclusive, so add 1.
- Even though there's a `while` loop inside a `for` loop, this is
  still O(n): `left` only ever moves forward and never resets, so
  the total number of `left++` operations across the entire run is
  at most `n`.
- The `? 0 : minLen` ternary at the end handles the edge case where
  no valid subarray exists — `minLen` was never updated from
  `INT_MAX`, so return `0`.

## Fixed-Size vs Variable-Size Window

| | Fixed-Size | Variable-Size |
|---|---|---|
| Window size | Given (`k`) | Unknown, must find |
| Right pointer | Always moves by 1 | Always moves by 1 |
| Left pointer | Always moves by 1 | Only moves when condition met |
| Inner loop | None needed | `while` to shrink |

## Complexity

- **Time:** O(n) — each element is added once (`right++`) and
  removed at most once (`left++`).
- **Space:** O(1) — three variables only.
