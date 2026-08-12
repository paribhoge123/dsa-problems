# 2011. Final Value of Variable After Performing Operations

**Link:** https://leetcode.com/problems/final-value-of-variable-after-performing-operations/
**Difficulty:** Easy
**Approach:** Plain loop — single character check per operation
**Time:** O(n)   **Space:** O(1)

## Problem

Variable `X` starts at `0`. Given an array of operation strings
(`"++X"`, `"X++"`, `"--X"`, `"X--"`), apply each one in order and
return the final value of `X`.

## Idea

Instead of comparing the entire string for each of the four forms,
notice that the **middle character** (index `1`) of every operation
string is always the telltale sign:

```
"++X"  → operations[i][1] = '+'   (increment)
"X++"  → operations[i][1] = '+'   (increment)
"--X"  → operations[i][1] = '-'   (decrement)
"X--"  → operations[i][1] = '-'   (decrement)
```

A single character check on `operations[i][1]` covers all four
forms — no need to compare the whole string.

`operations[i][1]` uses double indexing: first pick the string at
position `i` in the array, then pick the character at position `1`
inside that string. Strings are just arrays of characters, so they
can be indexed exactly like a plain array.

## Code

```cpp
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;

        for (int i = 0; i < operations.size(); i++) {
            if (operations[i][1] == '+') {
                x++;
            } else {
                x--;
            }
        }

        return x;
    }
};
```

## Step-by-Step Trace

```
operations = ["--X", "X++", "X++"]    x=0

i=0: operations[0][1] = '-' -> x-- -> x=-1
i=1: operations[1][1] = '+' -> x++ -> x=0
i=2: operations[2][1] = '+' -> x++ -> x=1

Result: 1
```

## Key Insights

- Strings in C++ are just arrays of characters — `s[i]` gives you
  the character at position `i`, the same way `arr[i]` gives you
  the element at position `i` in an integer array.
- `operations[i][1]` is double indexing: pick the i-th string from
  the outer array, then pick the character at index 1 inside it.
- Looking for a pattern in the data (middle character is always the
  meaningful one) avoids writing four separate string comparisons —
  a useful habit when working with strings that follow a fixed
  format.

## Complexity

- **Time:** O(n) — one pass through the operations array, O(1) per
  operation.
- **Space:** O(1) — only one variable `x` used.
