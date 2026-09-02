LeetCode 53 — Maximum Subarray

🧩 Problem

Given an integer array "nums", find the subarray with the largest sum and return its sum.

A subarray is a contiguous part of the array.

Example

Input:

nums = [-2,1,-3,4,-1,2,1,-5,4]

Output:

6

Explanation:

The subarray "[4,-1,2,1]" has the maximum sum:

4 + (-1) + 2 + 1 = 6

---

💡 Approach — Kadane's Algorithm

We keep track of two values:

- "currSum" → sum of the current subarray
- "maxSum" → maximum sum found so far

For every element:

1. Add the element to "currSum".
2. Update "maxSum" with the maximum of "currSum" and "maxSum".
3. If "currSum" becomes negative, reset it to "0".

Why reset when "currSum < 0"?

A negative sum can only decrease the sum of any subarray that comes after it.

So, instead of carrying a negative sum forward, we start a new subarray from the next element.

---

💻 C++ Solution

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0;
        int maxSum = INT_MIN;

        for (int val : nums) {
            currSum += val;
            maxSum = max(currSum, maxSum);

            if (currSum < 0) {
                currSum = 0;
            }
        }

        return maxSum;
    }
};

---

🔍 Dry Run

For:

nums = [-2, 1, -3, 4, -1, 2, 1]

Element| "currSum"| "maxSum"
-2| -2| -2
1| 1| 1
-3| -2| 1
4| 4| 4
-1| 3| 4
2| 5| 5
1| 6| 6

Answer:

6

---

⏱️ Complexity

- Time Complexity: "O(n)"
- Space Complexity: "O(1)"

We traverse the array only once and use only two variables.

---

🧠 Key Takeaway

«If the current subarray has a negative sum, it is better to discard it and start fresh.»

This simple idea leads to Kadane's Algorithm, one of the most important array techniques for finding maximum subarray sums.
