# 1480. Running Sum of 1d Array

**Link:** https://leetcode.com/problems/running-sum-of-1d-array/
**Difficulty:** Easy
**Approach:** Plain loop — running total (no hash map, no two pointers)
**Time:** O(n)   **Space:** O(1) extra (modifies input in place)

## Problem

Given an array `nums`, return a new array `runningSum` where
`runningSum[i]` is the sum of all elements from index `0` up to and
including index `i`.

## Idea

Keep a single running variable `sum` that accumulates as the loop
moves forward. At each index `i`:
1. Add `nums[i]` to `sum`.
2. Overwrite `nums[i]` with the updated `sum`.

Since `sum` already holds the total of everything before the current
index, only the *one new* value needs to be added each step — no
need to re-sum from the start every time.

The result can be written directly back into `nums`, avoiding the
need for a separate output array.

## Code

```cpp
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum = sum + nums[i];
            nums[i] = sum;
        }

        return nums;
    }
};
```

## Step-by-Step Trace

```
nums = [1, 2, 3, 4]    sum = 0

i=0: sum = 0+1 = 1;  nums[0] = 1   -> [1, 2, 3, 4]
i=1: sum = 1+2 = 3;  nums[1] = 3   -> [1, 3, 3, 4]
i=2: sum = 3+3 = 6;  nums[2] = 6   -> [1, 3, 6, 4]
i=3: sum = 6+4 = 10; nums[3] = 10  -> [1, 3, 6, 10]

Result: [1, 3, 6, 10]
```

## Key Insights

- This is the most basic array pattern: a single accumulator
  variable updated once per element, no auxiliary data structure
  needed.
- Modifying `nums` in place (via the `&` reference parameter) avoids
  allocating a second array — the same read-only-vs-modify tradeoff
  from earlier problems, just used here on purpose to save space.

## Complexity

- **Time:** O(n) — one pass through the array.
- **Space:** O(1) extra — result is written back into the input
  array instead of a new one.
