# Single Element in a Sorted Array

## Problem Statement

You are given a sorted array `A` in which every element appears exactly twice except for one element, which appears only once.

Find and return the single element in the array.

**Constraints:**
- The array is sorted in non-decreasing order.
- Every element appears exactly twice, except one element.
- The solution should have `O(log n)` time complexity and `O(1)` space complexity.

## Approach: Binary Search

Since the array is sorted, we can use **Binary Search** instead of checking every element.

### Key Observation

Before the single element:
- The first occurrence of every pair is at an even index.
- The second occurrence is at an odd index.

After the single element:
- This pattern gets disturbed.
- The first occurrence of every pair appears at an odd index.
- The second occurrence appears at an even index.

We use this pattern to eliminate half of the search space.

### Algorithm

1. If the array contains only one element, return it.
2. Initialize two pointers:
   - `st = 0`
   - `end = n - 1`
3. Calculate the middle index using binary search.
4. Handle boundary conditions:
   - If `mid == 0` and the first two elements are different, return `A[mid]`.
   - If `mid == n-1` and the last two elements are different, return `A[mid]`.
5. Check whether the middle element is different from both its neighbors. If yes, return it.
6. If `mid` is even:
   - If `A[mid-1] == A[mid]`, search the left half.
   - Otherwise, search the right half.
7. If `mid` is odd:
   - If `A[mid-1] == A[mid]`, search the right half.
   - Otherwise, search the left half.
8. Continue until the single element is found.

## C++ Solution

```cpp
class Solution {
public:
    int singleNonDuplicate(vector<int>& A) {
        int n = A.size();

        if(n == 1) return A[0];

        int st = 0, end = n - 1;

        while(st <= end) {
            int mid = st + (end - st) / 2;

            if(mid == 0 && A[0] != A[1])
                return A[mid];

            if(mid == n-1 && A[n-1] != A[n-2])
                return A[mid];

            if(A[mid-1] != A[mid] &&
               A[mid] != A[mid+1])
                return A[mid];

            if(mid % 2 == 0) {
                if(A[mid-1] == A[mid]) {
                    end = mid - 1;
                } else {
                    st = mid + 1;
                }
            } else {
                if(A[mid-1] == A[mid]) {
                    st = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }

        return -1;
    }
};
```

## Complexity Analysis

- **Time Complexity: O(log n)**  
  Binary search eliminates half of the search space in every iteration.

- **Space Complexity: O(1)**  
  Only a constant number of variables are used.

## Example

**Input:**
```cpp
A = {1, 1, 2, 3, 3, 4, 4}
```

**Output:**
```cpp
2
```

**Explanation:**

Every element appears twice except `2`, which appears only once.

Therefore, the single non-duplicate element is `2`.

## Key Learning

This problem demonstrates how binary search can be modified to work with patterns in a sorted array.

Instead of searching for a particular value, we use the index parity (even/odd) to identify which half contains the single element.
