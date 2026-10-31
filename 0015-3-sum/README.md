# 3Sum (C++)

Find all **unique triplets** in an array that add up to `0`.

## Problem

Given an integer array `nums`, return all triplets `[nums[i], nums[j], nums[k]]` such that:

- `i != j`, `i != k`, `j != k`
- `nums[i] + nums[j] + nums[k] == 0`
- The result contains **no duplicate triplets**

**Example**

```
Input:  nums = [-1, 0, 1, 2, -1, -4]
Output: [[-1, -1, 2], [-1, 0, 1]]
```

## Approach: Sort + Two Pointers

1. **Sort** the array so equal values sit next to each other and two pointers can work.
2. **Fix** one number `nums[i]` as the first element of the triplet.
3. Use **two pointers** (`left = i + 1`, `right = n - 1`) on the remaining part to find two numbers that sum to `-nums[i]`:
   - `sum < 0` → move `left` right (need a bigger sum)
   - `sum > 0` → move `right` left (need a smaller sum)
   - `sum == 0` → record the triplet, then move both pointers inward
4. **Skip duplicates** so the same triplet is never recorded twice.

### Duplicate handling

| Where | Rule | Why |
|-------|------|-----|
| `i` | skip if `nums[i] == nums[i-1]` | That value was already tried as the first element |
| `left` / `right` | after a match, skip repeated values | Prevents recording the same pair again |

> Duplicates are allowed **inside** a triplet (e.g. `[-1, -1, 2]`), but the same value must not be used as the **first** element twice.

### Early exit

If `nums[i] > 0`, stop. The array is sorted, so all remaining numbers are positive and the sum can never be `0`.

## Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {
            if (nums[i] > 0) break;                          // no way to reach 0
            if (i > 0 && nums[i] == nums[i - 1]) continue;   // skip duplicate first element

            int left = i + 1, right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum < 0) {
                    left++;
                } else if (sum > 0) {
                    right--;
                } else {
                    result.push_back({nums[i], nums[left], nums[right]});

                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                }
            }
        }
        return result;
    }
};
```

## Dry Run

`nums = [-1, 0, 1, 2, -1, -4]` → sorted: `[-4, -1, -1, 0, 1, 2]`

| i | nums[i] | left, right | sum | action |
|---|---------|-------------|-----|--------|
| 0 | -4 | 1, 5 | -3 | left++ |
| 0 | -4 | 2, 5 | -3 | left++ |
| 0 | -4 | 3, 5 | -2 | left++ |
| 0 | -4 | 4, 5 | -1 | left++, ends |
| 1 | -1 | 2, 5 | 0 | record `[-1, -1, 2]` |
| 1 | -1 | 3, 4 | 0 | record `[-1, 0, 1]` |
| 2 | -1 | - | - | skipped (same as `i = 1`) |
| 3 | 0 | 4, 5 | 3 | right--, ends |
| 4 | 1 | - | - | `nums[i] > 0`, break |

**Result:** `[[-1, -1, 2], [-1, 0, 1]]`

## Complexity

| | Complexity | Notes |
|---|-----------|-------|
| Time | **O(n²)** | Sort is O(n log n); the loop with two pointers is O(n²) |
| Space | **O(1)** | Extra space, ignoring output and the sort's internal usage |

## Common Mistakes

1. Forgetting to sort before using two pointers.
2. Comparing `nums[i]` with `nums[i+1]` instead of `nums[i-1]`, which wrongly skips valid answers like `[-1, -1, 2]`.
3. Not moving `left` and `right` after recording a triplet (infinite loop).
4. Not skipping duplicates for `left` and `right` after a match.

## Related Problems

- 3Sum Closest
- 4Sum
- Two Sum II (sorted input)
