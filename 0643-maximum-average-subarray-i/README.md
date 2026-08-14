# 643. Maximum Average Subarray I

**Link:** https://leetcode.com/problems/maximum-average-subarray-i/
**Difficulty:** Easy
**Approach:** Sliding Window (fixed size)
**Time:** O(n)   **Space:** O(1)

## Problem

Given an array `nums` and integer `k`, find a contiguous subarray of
length `k` with the maximum average value. Return that average.

## Idea

A naive approach recalculates the sum of every window from scratch —
O(n × k). Sliding window avoids this: when the window moves one
step right, only two things change:
- One new element enters from the right (`nums[i]`)
- One old element leaves from the left (`nums[i - k]`)

So the new window sum = old window sum + new element - old element.
One addition and one subtraction per step — O(1) per slide.

**Two phases:**
1. Build the sum of the first window (`nums[0..k-1]`) before the
   main loop. This is the starting `windowSum` and `maxSum`.
2. Slide the window from position `k` to the end, updating
   `windowSum` and `maxSum` at each step.

`nums[i - k]` is the element that just left the left side of the
window — when the right edge is at `i`, the left edge is at `i - k`.

## Code

```cpp
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double windowSum = 0;
        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }

        double maxSum = windowSum;

        for (int i = k; i < nums.size(); i++) {
            windowSum += nums[i];
            windowSum -= nums[i - k];
            maxSum = max(maxSum, windowSum);
        }

        return maxSum / k;
    }
};
```

## Step-by-Step Trace

```
nums = [1, 12, -5, -6, 50, 3], k=4

Phase 1: windowSum = 1+12+(-5)+(-6) = 2,  maxSum=2

Phase 2:
i=4: windowSum = 2+50-1  = 51,  maxSum=max(2,51)=51
i=5: windowSum = 51+3-12 = 42,  maxSum=max(51,42)=51

Return: 51/4 = 12.75
```

## Key Insights

- `windowSum` and `maxSum` are separate variables with separate jobs:
  `windowSum` slides (add one, remove one), `maxSum` only ever grows
  (tracks the best window seen so far). Mixing them up is the most
  common mistake on this problem.
- `nums[i - k]` is the left-side element leaving the window — when
  the right edge is at index `i` and the window has size `k`, the
  left edge sits at `i - k`. This is why the loop starts at `i = k`
  rather than `i = 1`: we need `i - k >= 0` to be a valid index.
- Return `maxSum / k`, not `windowSum / k` — `windowSum` holds the
  last window's sum, not necessarily the best one.

## Complexity

- **Time:** O(n) — one O(k) pass for Phase 1, one O(n) pass for
  Phase 2.
- **Space:** O(1) — two running variables, no extra array.
