# 977. Squares of a Sorted Array

**Link:** https://leetcode.com/problems/squares-of-a-sorted-array/
**Difficulty:** Easy
**Approach:** Two Pointers — converge inward, fill result from the back
**Time:** O(n)   **Space:** O(n) (for the output array)

## Problem

Given a sorted array `nums` (which may include negative numbers),
return an array of the squares of each number, sorted in ascending
order.

## Idea

Because the input is sorted but may contain negatives, squaring can
scramble the order (e.g. `-4` squares to `16`, bigger than `3²=9`).
The key insight: the **largest** square in the array always comes
from one of the two **extremes** — the most negative or the most
positive number — never from the middle.

So:
- `left` and `right` start at the two ends of `nums` and move
  **inward** (toward the middle) — same convergence idea as other
  two-pointer problems.
- At each step, compare `nums[left]²` and `nums[right]²`. Whichever
  is bigger is the next-largest square remaining, so place it into
  the result — but since it's the *biggest remaining* value, it
  belongs at the **end** of the sorted output, not the front.
- A third pointer, `pos`, starts at the last index of `result` and
  moves backward by one after every placement, tracking where to
  write next.
- The pointer belonging to whichever value was placed moves inward
  (`left++` or `right--`); the other stays put for the next round.

## Code

```cpp
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        int left = 0;
        int right = n - 1;
        int pos = n - 1;

        while (left <= right) {
            if (nums[left] * nums[left] > nums[right] * nums[right]) {
                result[pos] = nums[left] * nums[left];
                left++;
            } else {
                result[pos] = nums[right] * nums[right];
                right--;
            }
            pos--;
        }

        return result;
    }
};
```

## Step-by-Step Trace

```
nums = [-4, -1, 0, 3, 10]
left=0, right=4, pos=4

Step 1: 16 vs 100 -> 100 bigger -> result[4]=100, right--, pos--
        left=0, right=3, pos=3

Step 2: 16 vs 9   -> 16 bigger  -> result[3]=16,  left++,  pos--
        left=1, right=3, pos=2

Step 3: 1 vs 9    -> 9 bigger   -> result[2]=9,   right--, pos--
        left=1, right=2, pos=1

Step 4: 1 vs 0    -> 1 bigger   -> result[1]=1,   left++,  pos--
        left=2, right=2, pos=0

Step 5: 0 vs 0    -> else branch -> result[0]=0,  right--, pos--
        left=2, right=1 -> loop ends (left > right)

Result: [0, 1, 9, 16, 100]
```

## Key Insights

- "Inward" means both pointers move toward the middle, closing the
  gap between them — same convergence idea as Reverse String and
  Valid Palindrome, just with a comparison instead of a swap.
- Filling the result array **from the back** is the key trick: since
  each step finds the *largest remaining* square, and the largest
  values belong at the end of an ascending sorted array, placing
  back-to-front naturally produces correct ascending order.
- A third tracking variable (`pos`) is needed here, separate from
  `left`/`right` — it tracks the output position, not an input range.
- The loop condition is `left <= right` (not `<`), since the case
  where `left == right` still represents one remaining value that
  needs to be placed.

## Complexity

- **Time:** O(n) — each element is visited exactly once as the
  pointers converge.
- **Space:** O(n) for the output array (required by the problem,
  since results can't overwrite the input while it's still being
  read from both ends).
