# 485. Max Consecutive Ones

**Link:** https://leetcode.com/problems/max-consecutive-ones/
**Difficulty:** Easy
**Approach:** Plain loop — track current streak + best streak
**Time:** O(n)   **Space:** O(1)

## Problem

Given a binary array `nums` (containing only `0`s and `1`s), find the
maximum number of consecutive `1`s in the array.

## Idea

Tracking a single "current streak" variable isn't enough — resetting
it to `0` on every `0` would lose the memory of an earlier, possibly
longer streak. Two variables are needed:

- **`count`** — the length of the *current* run of 1s. Resets to `0`
  every time a `0` is seen.
- **`maxCount`** — the best run seen so far across the whole array.
  Only ever grows, never resets.

At each `1`, increment `count` and check whether it's now bigger than
`maxCount`. At each `0`, reset `count` to `0` — `maxCount` is left
untouched, preserving the best streak found so far.

This "track current + track best-ever" pattern shows up repeatedly
in DSA (e.g. max subarray sum, longest substring problems).

## Code

```cpp
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxCount = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                count++;
                maxCount = max(maxCount, count);
            }
            if (nums[i] == 0) {
                count = 0;
            }
        }

        return maxCount;
    }
};
```

## Step-by-Step Trace

```
nums = [1, 1, 0, 1, 1, 1]    count=0, maxCount=0

i=0: nums[0]=1 -> count=1, maxCount=max(0,1)=1
i=1: nums[1]=1 -> count=2, maxCount=max(1,2)=2
i=2: nums[2]=0 -> count=0            (maxCount stays 2)
i=3: nums[3]=1 -> count=1, maxCount=max(2,1)=2
i=4: nums[4]=1 -> count=2, maxCount=max(2,2)=2
i=5: nums[5]=1 -> count=3, maxCount=max(2,3)=3

Result: 3
```

## Key Insights

- A single reset-on-zero counter alone loses history — without a
  separate `maxCount`, an earlier longer streak can be silently
  overwritten by a shorter one later in the array.
- `max(a, b)` is a built-in C++ function that returns whichever of
  the two values is larger — a clean way to guarantee a tracked
  "best so far" value never accidentally shrinks.
- The two `if` blocks are siblings (not nested) — exactly one runs
  per loop iteration, since `nums[i]` can't be both `1` and `0`.

## Complexity

- **Time:** O(n) — one pass through the array.
- **Space:** O(1) — only two counter variables used.
