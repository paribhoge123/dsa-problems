# 217. Contains Duplicate

**Link:** https://leetcode.com/problems/contains-duplicate/
**Difficulty:** Easy
**Approach:** Hash Set (unordered_set)
**Time:** O(n)   **Space:** O(n)

## Problem

Given an array `nums`, return `true` if any value appears **at least
twice** in the array, and `false` if every element is distinct.

## Idea

Unlike Majority Element, this problem doesn't need a *count* of each
number — it only needs a yes/no answer to "have I seen this number
before?" That makes `unordered_set` a better fit than
`unordered_map`: a set only tracks whether a value exists, with no
extra count attached.

Walk through `nums` once. For each number:
1. Check if it's already in the set.
2. If yes -> it's a duplicate, return `true` immediately.
3. If no -> add it to the set and move on.

If the loop finishes without ever finding a duplicate, return `false`.

## Code

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for (int i = 0; i < nums.size(); i++) {
            if (seen.count(nums[i])) {
                return true;
            }
            seen.insert(nums[i]);
        }

        return false;
    }
};
```

## Step-by-Step Trace

```
nums = [1, 2, 3, 1]

i=0: nums[0]=1, seen={} -> not found -> insert -> seen={1}
i=1: nums[1]=2, seen={1} -> not found -> insert -> seen={1,2}
i=2: nums[2]=3, seen={1,2} -> not found -> insert -> seen={1,2,3}
i=3: nums[3]=1, seen={1,2,3} -> FOUND -> return true
```

## Key Insights

- `seen.count(nums[i])` returns `1` if the value exists, `0` if not
  — no need to compare it to anything, its result is usable directly
  in an `if`.
- No `else` is needed after the `if (seen.count(...)) return true;`
  block. Since `return` exits the function immediately, any code
  written right after the `if` (not wrapped in `else`) only runs when
  the condition was false — an early return makes `else` unnecessary
  here.
- The insert must happen for every number that *isn't* a duplicate,
  or `seen` never accumulates anything and duplicates further down
  the array would never be detected.

## Complexity

- **Time:** O(n) — one pass through the array, each set operation
  (`count`, `insert`) is O(1) on average.
- **Space:** O(n) — worst case (no duplicates), every element ends
  up stored in `seen`.
