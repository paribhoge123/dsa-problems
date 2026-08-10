# 1929. Concatenation of Array

**Link:** https://leetcode.com/problems/concatenation-of-array/
**Difficulty:** Easy
**Approach:** Direct indexing, single pass
**Time:** O(n)   **Space:** O(n) (required for the output array)

## Problem

Given an array `nums` of length `n`, return an array `ans` of length
`2n` where `ans` is `nums` followed by itself.

## Idea

Pre-size the output array to `2n`, then in a single loop through
`nums`, write each element to two positions at once:
- `ans[i]` — the first copy, at the normal index
- `ans[i + n]` — the second copy, shifted forward by `n`

The `+n` offset keeps the two copies aligned: as `i` grows, both
target positions move together, so the second half always mirrors
the first half exactly.

## Code

```cpp
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2 * n);

        for (int i = 0; i < n; i++) {
            ans[i] = nums[i];
            ans[i + n] = nums[i];
        }

        return ans;
    }
};
```

## Step-by-Step Trace

```
nums = [1, 2, 1]    n=3

i=0: ans[0]=1, ans[3]=1   -> [1, _, _, 1, _, _]
i=1: ans[1]=2, ans[4]=2   -> [1, 2, _, 1, 2, _]
i=2: ans[2]=1, ans[5]=1   -> [1, 2, 1, 1, 2, 1]

Result: [1, 2, 1, 1, 2, 1]
```

## Key Insights

- No special technique needed here — just careful indexing.
  Pre-sizing `vector<int> ans(2 * n)` allocates all the space
  upfront, so both writes per iteration (`ans[i]` and `ans[i + n]`)
  are safe, direct assignments rather than `push_back` calls.
- Good practice for the basic mental model of "where does this index
  map to in the output," which becomes more important once problems
  involve more complex index arithmetic (e.g. 2D grids, sliding
  windows).

## Complexity

- **Time:** O(n) — one pass through `nums`, two writes per element.
- **Space:** O(n) — required for the output array; not counting the
  output, only O(1) extra space is used.
