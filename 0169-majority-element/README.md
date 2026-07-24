169. Majority Element

Link: https://leetcode.com/problems/majority-element/ Difficulty: Easy Approach: Hash Map (unordered_map) — count occurrences Time: O(n) Space: O(n)

Problem

Given an array nums of size n, return the element that appears more than ⌊n/2⌋ times. The problem guarantees a majority element always exists, so no "not found" case needs to be handled.

Idea
Walk through the array once and count how many times each number appears, using an unordered_map<int, int> where the key is the number and the value is its count.
Walk through the map and track the entry with the highest count. That number is the majority element.
Code
cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;

        // Step 1: count occurrences of each number
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }

        // Step 2: find the key with the highest count
        int maxCount = 0;
        int answer = -1;

        for (auto p : m) {
            if (p.second > maxCount) {
                answer = p.first;
                maxCount = p.second;
            }
        }

        return answer;
    }
};
Step-by-Step Trace
nums = [2, 2, 1, 1, 1, 2, 2]

Building the map:
see 2 -> m = {2: 1}
see 2 -> m = {2: 2}
see 1 -> m = {2: 2, 1: 1}
see 1 -> m = {2: 2, 1: 2}
see 1 -> m = {2: 2, 1: 3}
see 2 -> m = {2: 3, 1: 3}
see 2 -> m = {2: 4, 1: 3}

Final map: {2: 4, 1: 3}

Scanning the map for the max:
p = {2, 4}: 4 > 0  -> answer = 2, maxCount = 4
p = {1, 3}: 3 > 4  -> false, no update

Result: 2
Key Insights
m[nums[i]]++ relies on the unordered_map auto-insert behavior: accessing a missing key creates it with a default value of 0 before the increment runs — no need for an explicit "does this key exist" check.
When comparing counts in the second loop, maxCount must be assigned (maxCount = p.second), not incremented (maxCount++). Incrementing would silently track the wrong maximum and could let a smaller count overwrite the answer.
p in for (auto p : m) is a pair<int, int> — p.first is the number (key), p.second is its count (value).
Complexity
Time: O(n) — one pass to build the map, one pass over the map (at most n distinct keys) to find the max.
Space: O(n) — the map can hold up to n distinct keys in the worst case.
