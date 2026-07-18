# 1. Two Sum

**Link:** https://leetcode.com/problems/two-sum/
**Difficulty:** Easy
**Approach:** Hash Map (unordered_map)
**Time:** O(n)   **Space:** O(n)

## Idea
For each number, compute its "complement" (`target - nums[i]`).
Check if that complement was already seen using an `unordered_map`.
If yes, we found our pair. If no, store the current number and move on.

This avoids the brute-force O(n²) nested loop by trading space for time.

## Key Insight
Store the current number **after** checking for its complement — not before —
to avoid incorrectly pairing a number with itself.
