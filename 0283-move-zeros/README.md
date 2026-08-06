# Day 55 - Move Zeroes (LeetCode 283)

## 📌 Problem Statement

Given an integer array `nums`, move all `0`s to the end while maintaining the **relative order of the non-zero elements**.

**Note:** You must perform this operation **in-place** without making a copy of the array.

---

## 🧠 Approach

Since we need to modify the same array without using extra space, we use the **Two Pointer** technique.

* `i` → Traverses every element in the array.
* `j` → Points to the position where the next non-zero element should be placed.

Whenever we encounter a non-zero element:

1. Swap `nums[i]` with `nums[j]`.
2. Increment `j`.

If the current element is `0`, we simply continue to the next element.

This ensures that all non-zero elements are moved to the front while preserving their original order, and all zeros automatically shift to the end.

---

## 🔄 Dry Run

### Input

```text
nums = [0,1,0,3,12]
```

### Initial State

```text
i = 0
j = 0

[0,1,0,3,12]
```

### Iteration 1

`nums[i] = 0`

Ignore it.

```text
i = 1
j = 0
```

---

### Iteration 2

`nums[i] = 1`

Swap `nums[1]` and `nums[0]`

```text
[1,0,0,3,12]
```

Increment `j`

```text
j = 1
```

---

### Iteration 3

`nums[i] = 0`

Ignore it.

---

### Iteration 4

`nums[i] = 3`

Swap `nums[3]` and `nums[1]`

```text
[1,3,0,0,12]
```

Increment `j`

```text
j = 2
```

---

### Iteration 5

`nums[i] = 12`

Swap `nums[4]` and `nums[2]`

```text
[1,3,12,0,0]
```

Increment `j`

```text
j = 3
```

Final Output

```text
[1,3,12,0,0]
```

---

## 💻 C++ Solution

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int j = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};
```

---

## ⏱️ Time Complexity

* We traverse the array only once.

**Time Complexity:** **O(n)**

---

## 📦 Space Complexity

* No extra array or data structure is used.

**Space Complexity:** **O(1)**

---

## 🔑 Key Learning

* Learned how to solve an array problem using the **Two Pointer** technique.
* Used one pointer to traverse the array and another to track the position for the next non-zero element.
* Performed the operation **in-place**, avoiding extra memory.
* Preserved the relative order of non-zero elements while moving all zeros to the end.

---

## 🚀 Interview Tip

Whenever a problem asks you to:

* Modify the same array (**in-place**)
* Preserve the order of elements
* Move, remove, or rearrange elements

think about the **Two Pointer** approach before considering extra space. It often leads to an optimal solution with **O(n)** time and **O(1)** space.
