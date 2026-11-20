# Trapping Rain Water – LeetCode 42

## Problem
Given an array `height` representing the elevation map where the width of each bar is 1, calculate how much water can be trapped after raining.

## Approach: Prefix Maximum & Suffix Maximum (Arrays)

We use two additional arrays to calculate the maximum height of pillars on both sides of every index.

### 1. Left Maximum Array
- `leftMax[i]` stores the maximum height from index `0` to `i`.
- Initialize `leftMax[0] = height[0]`.
- Traverse from left to right.

Formula:
```cpp
leftMax[i] = max(leftMax[i-1], height[i]);
```

### 2. Right Maximum Array
- `rightMax[i]` stores the maximum height from index `i` to `n-1`.
- Initialize `rightMax[n-1] = height[n-1]`.
- Traverse from right to left.

Formula:
```cpp
rightMax[i] = max(rightMax[i+1], height[i]);
```

### 3. Calculate Trapped Water

The water trapped at each index depends on the smaller of the maximum heights on its left and right.

**Formula:**

```cpp
water[i] = min(leftMax[i], rightMax[i]) - height[i];
```

Add the trapped water at every index to calculate the total.

## C++ Solution

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> leftMax(n);
        vector<int> rightMax(n);

        leftMax[0] = height[0];

        for(int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i-1], height[i]);
        }

        rightMax[n-1] = height[n-1];

        for(int i = n-2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i+1], height[i]);
        }

        int water = 0;

        for(int i = 0; i < n; i++) {
            water += min(leftMax[i], rightMax[i]) - height[i];
        }

        return water;
    }
};
```

## Example

**Input:**
```cpp
height = [4,2,0,3,2,5]
```

| Index | Height | Left Max | Right Max | Water |
|---|---:|---:|---:|---:|
| 0 | 4 | 4 | 5 | 0 |
| 1 | 2 | 4 | 5 | 2 |
| 2 | 0 | 4 | 5 | 4 |
| 3 | 3 | 4 | 5 | 1 |
| 4 | 2 | 4 | 5 | 2 |
| 5 | 5 | 5 | 5 | 0 |

**Output:**
```cpp
9
```

## Complexity Analysis

- **Time Complexity:** O(n)
  - One traversal to calculate `leftMax`.
  - One traversal to calculate `rightMax`.
  - One traversal to calculate trapped water.

- **Space Complexity:** O(n)
  - Two additional arrays of size n.

## Key Learnings

- Understanding prefix maximum and suffix maximum arrays.
- Using `max()` to maintain maximum values while traversing.
- Using `min()` to determine the water level.
- Applying precomputation to solve an array problem efficiently.

**LeetCode:** 42 – Trapping Rain Water

**Topic:** Arrays | Prefix Maximum | Suffix Maximum
