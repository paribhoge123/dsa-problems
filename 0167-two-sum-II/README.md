# Day 54 - Two Sum II - Input Array Is Sorted (LeetCode 167)

## 📌 Problem Statement

Given a **1-indexed** array of integers `numbers` that is sorted in **non-decreasing order**, find two numbers such that they add up to a specific `target`.

Return the **indices (1-based)** of the two numbers as an integer array of size 2.

### Constraints

* There is **exactly one solution**.
* You **cannot use the same element twice**.
* The array is already **sorted**.

---

## 🧠 Intuition

Since the array is sorted, we can use the **Two Pointer** technique instead of a HashMap.

* Place one pointer (`left`) at the beginning.
* Place another pointer (`right`) at the end.

Now compare the sum of the two elements with the target.

### Cases

### Case 1: Sum equals target

We found the required pair.

Return their **1-based indices**.

### Case 2: Sum is smaller than target

Example:

```text
numbers = [2,3,4,7,11,15]
target = 9

left = 2
right = 4

2 + 4 = 6
```

The sum is too small.

Since the array is sorted, moving the **left pointer to the right** increases the sum.

So,

```cpp
left++;
```

---

### Case 3: Sum is greater than target

Example:

```text
numbers = [2,3,4,7,11,15]
target = 9

left = 2
right = 15

2 + 15 = 17
```

The sum is too large.

Since the array is sorted, moving the **right pointer to the left** decreases the sum.

So,

```cpp
right--;
```

---

## 🔄 Dry Run

### Input

```text
numbers = [2,7,11,15]
target = 9
```

Initial pointers

```text
left = 0
right = 3
```

Current values

```text
2 + 15 = 17
```

17 > 9

Move right

```text
right = 2
```

Now

```text
2 + 11 = 13
```

13 > 9

Move right

```text
right = 1
```

Now

```text
2 + 7 = 9
```

Target found.

Return

```text
{1,2}
```

Remember to return **1-based indexing**, so we add `1` to both indices.

---

## 💻 C++ Solution

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {

            int sum = numbers[left] + numbers[right];

            if (sum == target) {
                return {left + 1, right + 1};
            }
            else if (sum < target) {
                left++;
            }
            else {
                right--;
            }
        }

        return {};
    }
};
```

---

## ⏱️ Time Complexity

Each pointer moves at most once across the array.

```
Time Complexity = O(n)
```

---

## 📦 Space Complexity

Only two pointers are used.

```
Space Complexity = O(1)
```

---

## 🔍 Why Two Pointers?

A HashMap solution would also work.

* Time: **O(n)**
* Space: **O(n)**

Since the array is already sorted, we can take advantage of that property and solve it using two pointers.

* Same **O(n)** time
* Better **O(1)** space

This makes the Two Pointer approach the optimal solution.

---

## ✅ Key Learnings

* Recognize when a **sorted array** can be solved using **Two Pointers**.
* If the current sum is **too small**, move the **left pointer** to increase the sum.
* If the current sum is **too large**, move the **right pointer** to decrease the sum.
* Always check whether the problem expects **0-based** or **1-based** indexing.
* Look for problem constraints that hint at a more optimal solution.
