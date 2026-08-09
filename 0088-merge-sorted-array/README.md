# 88. Merge Sorted Array

**Link:** https://leetcode.com/problems/merge-sorted-array/
**Difficulty:** Easy
**Approach:** Two Pointers — merge from the back
**Time:** O(m + n)   **Space:** O(1)

## Problem

`nums1` has size `m + n`: the first `m` elements are real sorted
values, the last `n` are `0` placeholders. `nums2` has size `n`,
fully filled with sorted values. Merge `nums2` into `nums1` in-place
so `nums1` becomes one sorted array of size `m + n`.

## Idea

Merging from the **front** would immediately overwrite real,
not-yet-compared values in `nums1` with merged results, corrupting
data still needed for later comparisons.

Instead, since `nums1` has empty space at the **end**, merge
**backward**: repeatedly compare the largest remaining elements of
each array and place the bigger one into the last open slot.
Because writes always land in space that's either empty or already
read, nothing gets corrupted.

Three pointers are used:
- `p1` — last real element in `nums1` (index `m - 1`)
- `p2` — last element in `nums2` (index `n - 1`)
- `p`  — next slot to fill in `nums1`, starting at the very end
  (index `m + n - 1`)

At each step, whichever of `nums1[p1]` / `nums2[p2]` is bigger gets
placed at `nums1[p]`; that value's pointer moves back one, and `p`
always moves back one after every placement.

**The tricky edge case:** if `p2` still has leftover elements after
`p1` runs out, those values are smaller than everything already
placed and must be explicitly copied into the front of `nums1` — an
explicit second loop handles this. If `p1` runs out first instead,
whatever remains in `nums1[0..p1]` is already sorted and already in
the correct place, so nothing further needs to happen.

## Code

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1;
        int p2 = n - 1;
        int p = m + n - 1;

        while (p1 >= 0 && p2 >= 0) {
            if (nums1[p1] > nums2[p2]) {
                nums1[p] = nums1[p1];
                p1--;
            } else {
                nums1[p] = nums2[p2];
                p2--;
            }
            p--;
        }

        while (p2 >= 0) {
            nums1[p] = nums2[p2];
            p2--;
            p--;
        }
    }
};
```

## Step-by-Step Trace

```
nums1 = [1, 2, 3, 0, 0, 0], m=3
nums2 = [2, 5, 6], n=3
p1=2, p2=2, p=5

3 vs 6 -> 6 bigger -> nums1[5]=6, p2=1, p=4
3 vs 5 -> 5 bigger -> nums1[4]=5, p2=0, p=3
3 vs 2 -> 3 bigger -> nums1[3]=3, p1=1, p=2
2 vs 2 -> else branch -> nums1[2]=2, p2=-1, p=1

Main loop ends (p2 < 0). Leftover loop: p2 < 0, nothing to copy.

Result: [1, 2, 2, 3, 5, 6]
```

## Key Insights

- Working backward avoids overwriting values in `nums1` before
  they've been read — a common trap when the "obvious" front-to-back
  merge would corrupt data.
- Careful with which pointer indexes which array: `p1` always reads
  from `nums1`, `p2` always reads from `nums2` — mixing these up
  (e.g. `nums1[p2]`) is an easy but serious bug.
- The leftover loop only ever needs to handle `p2` (copying
  remaining `nums2` values) — if `p1` has leftovers instead, they're
  already correctly positioned and require no action.
- Always move the **pointer** (`p1--`, `p2--`, `p--`), never the
  value stored in the array (`nums1[p1]--` would corrupt data).

## Complexity

- **Time:** O(m + n) — each element from both arrays is visited and
  placed exactly once.
- **Space:** O(1) — merges in-place within `nums1`'s existing
  allocated space, no extra array needed.
