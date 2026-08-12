# 1920. Build Array from Permutation

**Link:** https://leetcode.com/problems/build-array-from-permutation/
**Difficulty:** Easy
**Approach:** Direct index mapping — double indexing
**Time:** O(n)   **Space:** O(n) (required for the output array)

## Problem

Given a zero-based permutation `nums` (contains all integers from
`0` to `n-1` exactly once), return an array `ans` where:
```
ans[i] = nums[nums[i]]
```

## Idea

The entire solution is one line inside a loop. `nums[nums[i]]`
uses **double indexing**: first, `nums[i]` gives you a value from
the array — then that value is used *again* as an index to look up
another value in `nums`. The result goes into `ans[i]`.

This is the same "index into something, use the result as an index
again" pattern as `operations[i][1]` in Problem 2011 — just applied
to an integer array instead of a string array.

## Code

```cpp
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            ans[i] = nums[nums[i]];
        }

        return ans;
    }
};
```

## Step-by-Step Trace

```
nums = [0, 2, 1, 5, 3, 4]

i=0: nums[0]=0 -> nums[0]=0  -> ans[0]=0
i=1: nums[1]=2 -> nums[2]=1  -> ans[1]=1
i=2: nums[2]=1 -> nums[1]=2  -> ans[2]=2
i=3: nums[3]=5 -> nums[5]=4  -> ans[3]=4
i=4: nums[4]=3 -> nums[3]=5  -> ans[4]=5
i=5: nums[5]=4 -> nums[4]=3  -> ans[5]=3

Result: [0, 1, 2, 4, 5, 3]
```

## Key Insights

- Double indexing (`nums[nums[i]]`) — use a value from the array as
  an index back into the same array. Safe here because `nums` is a
  permutation of `0..n-1`, so every `nums[i]` is a valid index.
- Same pattern as indexing into a string: `s[i]` gives a character,
  `arr[i]` gives a number — both can be chained as long as the
  result is a valid index.

## Complexity

- **Time:** O(n) — one pass, one double-index lookup per element.
- **Space:** O(n) for the output array; O(1) extra space otherwise.
