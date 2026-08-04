# Day 53 - Ransom Note (LeetCode 383)

## 📌 Problem Statement

Given two strings `ransomNote` and `magazine`, return `true` if `ransomNote` can be constructed using the letters from `magazine`; otherwise, return `false`.

### Rules

* Each character in `magazine` can be used **only once**.
* Every character required by `ransomNote` must be available in `magazine` with the required frequency.

---

## 🧠 Approach

The main idea is to count the frequency of each character in the `magazine` and then verify whether the `ransomNote` can be formed using those characters.

### Steps

1. Create a **HashMap (`unordered_map<char, int>`)** to store the frequency of every character in `magazine`.
2. Traverse the `magazine` string and increment the count of each character.
3. Traverse the `ransomNote` string.
4. For each character:

   * If its frequency is `0`, return `false`.
   * Otherwise, decrement its frequency since that character has been used.
5. If all characters are successfully processed, return `true`.

---

## 💻 C++ Solution

```cpp
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        unordered_map<char, int> mp;

        // Count frequency of characters in magazine
        for (char ch : magazine) {
            mp[ch]++;
        }

        // Check if ransom note can be constructed
        for (char ch : ransomNote) {
            if (mp[ch] == 0) {
                return false;
            }
            mp[ch]--;
        }

        return true;
    }
};
```

---

## ⏱️ Time Complexity

* Building the frequency map: **O(m)**
* Traversing the ransom note: **O(n)**

**Overall Time Complexity:** **O(m + n)**

where:

* `m` = length of `magazine`
* `n` = length of `ransomNote`

---

## 📦 Space Complexity

* **O(k)**, where `k` is the number of distinct characters stored in the HashMap.
* Since the problem contains only lowercase English letters (`a`–`z`), `k ≤ 26`, making the space complexity effectively **O(1)**.

---

## 🔑 Key Learning

* Frequency counting using `unordered_map`
* Using a HashMap for efficient lookups
* Decrementing frequencies to represent resource consumption
* Checking character availability based on **count**, not just presence

---

## 🚀 Interview Tip

For this problem, an even more optimized solution uses an array of size **26** instead of a HashMap because the input consists only of lowercase English letters. However, the HashMap approach is an excellent way to understand the frequency-counting pattern, which is useful in many string and HashMap problems.
