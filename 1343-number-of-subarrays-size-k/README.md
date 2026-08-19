# 1343. Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold

**Link:** https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/
**Difficulty:** Medium
**Approach:** Sliding Window (fixed size)
**Time:** O(n)   **Space:** O(1)

## Problem

Given array `arr`, integer `k`, and integer `threshold`, return the
number of subarrays of length `k` whose average is >= `threshold`.

## Idea

Same fixed-size sliding window skeleton as Maximum Average Subarray
and Maximum Number of Vowels — just a different end condition.
Instead of tracking the **best** window, count how many windows
**qualify** (average >= threshold).

Two phases:
1. Build the first window sum, check if it qualifies.
2. Slide the window (add new element, remove old element), check
   each new window against the threshold.

## Code

```cpp
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        double windowSum = 0;
        for (int i = 0; i < k; i++) {
            windowSum += arr[i];
        }

        int count = 0;
        if (windowSum / k >= threshold) count++;

        for (int i = k; i < arr.size(); i++) {
            windowSum += arr[i];
            windowSum -= arr[i - k];
            if (windowSum / k >= threshold) count++;
        }

        return count;
    }
};
```

## Step-by-Step Trace

```
arr = [2,2,2,2,5,5,5,8], k=3, threshold=4

Phase 1: windowSum = 2+2+2 = 6.  6/3=2 >= 4? No.  count=0

Phase 2:
i=3: +2-2=6.   6/3=2  >= 4? No.
i=4: +5-2=9.   9/3=3  >= 4? No.
i=5: +5-2=12.  12/3=4 >= 4? Yes -> count=1
i=6: +5-5=12.  12/3=4 >= 4? Yes -> count=2
i=7: +8-5=15.  15/3=5 >= 4? Yes -> count=3

Result: 3
```

## Key Insights

- Same skeleton as all fixed-size window problems: build first
  window, check it, then slide (add new, remove old at i-k), check
  each new window.
- The only thing that changes across fixed-size window problems is
  what you're tracking (max, count, sum) and what condition you
  check per window.
- Using `double` for `windowSum` avoids integer division truncation
  when computing the average.

## Complexity

- **Time:** O(n) — one O(k) pass for Phase 1, one O(n) pass for
  Phase 2.
- **Space:** O(1) — two variables only.
