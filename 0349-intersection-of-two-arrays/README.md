# 349. Intersection of Two Arrays

**Link:** https://leetcode.com/problems/intersection-of-two-arrays/
**Difficulty:** Easy
**Approach:** Hash Set — two-phase lookup
**Time:** O(n + m)   **Space:** O(n + m)

## Problem

Given two arrays `nums1` and `nums2`, return their intersection —
elements that appear in **both** arrays. Each element in the output
must be unique, and order doesn't matter.

## Idea

A brute-force nested loop (check every element of `nums1` against
every element of `nums2`) works but costs O(n * m) — for every
element in one array, the whole other array is scanned.

Instead, use two hash sets in two phases:

1. **Phase 1:** Build a set from all of `nums1`. This gives O(1)
   average lookups for "does this number exist in nums1?" and
   automatically discards duplicates within `nums1` itself.
2. **Phase 2:** Loop through `nums2` once. For each number, check if
   it exists in `set1` (`.count()`). If so, insert it into a second
   set, `result`.

Using a **set** (not a vector) for `result` handles the "no
duplicates in output" requirement automatically — inserting the same
value twice into a set has no effect, no manual duplicate-checking
needed.

Finally, convert `result` (a set) into a `vector` to match the
required return type.

## Code

```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> result;

        for (int i = 0; i < nums2.size(); i++) {
            if (set1.count(nums2[i])) {
                result.insert(nums2[i]);
            }
        }

        return vector<int>(result.begin(), result.end());
    }
};
```

## Step-by-Step Trace

```
nums1 = [1, 2, 2, 1], nums2 = [2, 2]

Phase 1: set1 = {1, 2}   (duplicates from nums1 collapsed automatically)

Phase 2:
i=0: nums2[0]=2 -> set1.count(2)=1 -> result.insert(2) -> result={2}
i=1: nums2[1]=2 -> set1.count(2)=1 -> result.insert(2) -> result={2} (no change, already present)

Return: [2]
```

## Key Insights

- `unordered_set<int> set1(nums1.begin(), nums1.end())` builds a set
  directly from a range of iterators — a compact way to dump an
  entire vector into a set in one line.
- Reuses the exact `set.count(value)` existence-check pattern from
  Contains Duplicate, just checking against a *different* set built
  from the other array.
- Using a set (not a vector) for the output is what guarantees
  uniqueness — inserting a duplicate is a no-op, so no extra
  "have I already added this" check is needed.

## Complexity

- **Time:** O(n + m) — one pass to build `set1` from `nums1` (n
  elements), one pass through `nums2` (m elements) with O(1) average
  set operations.
- **Space:** O(n + m) — worst case, both sets could hold up to n and
  m elements respectively.
