# 1470. Shuffle the Array

**Link:** https://leetcode.com/problems/shuffle-the-array/
**Difficulty:** Easy
**Approach:** Direct index mapping, single pass
**Time:** O(n)   **Space:** O(n) (required for the output array)

## Problem

`nums` has length `2n`: the first `n` elements are `x1..xn`, the
last `n` elements are `y1..yn`. Return the array interleaved as
`x1, y1, x2, y2, ..., xn, yn`.

## Idea

`nums` is really two halves glued together:
- `x_i = nums[i]` for `i` in `0..n-1`
- `y_i = nums[i + n]` for `i` in `0..n-1`

The output alternates `x, y, x, y, ...`. Working out where each pair
lands in the output:

| i | x position in output | y position in output |
|---|---|---|
| 0 | 0 | 1 |
| 1 | 2 | 3 |
| 2 | 4 | 5 |

The pattern: `x_i` goes to position `2*i`, and `y_i` goes to
position `2*i + 1`. A single loop over `i` from `0` to `n-1` places
both values directly using this formula — no need to build or store
the `x`/`y` halves separately.

## Code

```cpp
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2 * n);

        for (int i = 0; i < n; i++) {
            ans[2*i] = nums[i];
            ans[2*i + 1] = nums[i + n];
        }

        return ans;
    }
};
```

## Step-by-Step Trace

```
nums = [2, 5, 1, 3, 4, 7], n=3

i=0: ans[0]=nums[0]=2,  ans[1]=nums[3]=3   -> [2, 3, _, _, _, _]
i=1: ans[2]=nums[1]=5,  ans[3]=nums[4]=4   -> [2, 3, 5, 4, _, _]
i=2: ans[4]=nums[2]=1,  ans[5]=nums[5]=7   -> [2, 3, 5, 4, 1, 7]

Result: [2, 3, 5, 4, 1, 7]
```

## Key Insights

- No auxiliary arrays for `x` or `y` are needed — both halves are
  read directly from `nums` using index offsets (`nums[i]` and
  `nums[i + n]`).
- The core skill here is working out an index formula (`2*i` and
  `2*i + 1`) by writing out a small table of examples first, rather
  than guessing — a useful habit for any problem involving
  interleaving, reshaping, or repositioning array elements.

## Complexity

- **Time:** O(n) — one pass, two writes per iteration.
- **Space:** O(n) for the output array; O(1) extra space otherwise.
