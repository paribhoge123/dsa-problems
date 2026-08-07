# 26. Remove Duplicates from Sorted Array

**Link:** https://leetcode.com/problems/remove-duplicates-from-sorted-array/
**Difficulty:** Easy
**Approach:** Two Pointers — fast/slow (overwrite, not swap)
**Time:** O(n)   **Space:** O(1)

## Problem

Given a sorted array `nums`, remove duplicates in-place so each
element appears only once. Return `k` — the number of unique
elements. The first `k` elements of `nums` should hold the result;
what comes after doesn't matter.

## Idea

Same fast/slow pointer mechanic as Move Zeroes, but the condition
flips: instead of "is this non-zero?", it's "is this different from
the last unique element we wrote?"

Since the array is **sorted**, duplicates are always adjacent — so
comparing `nums[fast]` to `nums[slow]` is enough to detect a new
unique value.

- `slow` tracks the position of the last unique element placed.
- `fast` scans every element looking for something new.
- When `fast` finds a value different from `nums[slow]`, advance
  `slow` and overwrite `nums[slow]` with `nums[fast]`.
- No swapping needed — we only care about the first `k` elements,
  so overwriting is enough.

## Code

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0;

        for (int fast = 1; fast < nums.size(); fast++) {
            if (nums[fast] != nums[slow]) {
                slow++;
                nums[slow] = nums[fast];
            }
        }

        return slow + 1;
    }
};
```

## Step-by-Step Trace

```
nums = [0, 0, 1, 1, 2]    slow=0

fast=1: nums[1]=0 == nums[0]=0 -> skip
fast=2: nums[2]=1 != nums[0]=0 -> slow=1, nums[1]=1  -> [0,1,1,1,2]
fast=3: nums[3]=1 == nums[1]=1 -> skip
fast=4: nums[4]=2 != nums[1]=1 -> slow=2, nums[2]=2  -> [0,1,2,1,2]

return slow+1 = 3
First 3 elements: [0, 1, 2]  ✅
```

## Key Insights

- Sorted array = duplicates are always adjacent = one comparison
  (`nums[fast] != nums[slow]`) detects all new unique values.
- `fast` is incremented by the `for` loop automatically — never
  manually increment it inside the `if` block or elements get skipped.
- Overwrite (not swap) is enough here since only the first `k`
  positions matter — no need to preserve the original values after
  position `slow`.

## Complexity

- **Time:** O(n) — one pass through the array.
- **Space:** O(1) — in-place, only two pointer variables used.
