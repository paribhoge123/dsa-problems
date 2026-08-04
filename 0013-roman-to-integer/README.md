# 13. Roman to Integer

**Link:** https://leetcode.com/problems/roman-to-integer/
**Difficulty:** Easy
**Approach:** Hash Map as a lookup table + single pass
**Time:** O(n)   **Space:** O(1) (map holds at most 7 fixed entries)

## Problem

Given a Roman numeral string, convert it to its integer value.

Roman numeral symbol values:
```
I=1   V=5   X=10   L=50   C=100   D=500   M=1000
```

Normally, symbols are added left to right. But if a **smaller** value
appears **immediately before** a **larger** value, it is **subtracted**
instead (e.g. IV=4, IX=9, XL=40, XC=90, CD=400, CM=900).

## Idea

Use a hash map as a **static lookup table** — not for counting or
existence-checking, but to instantly retrieve each symbol's value.
This is a different use case from previous hash map problems.

Walk through the string once. At each character, compare its value
to the **next** character's value:
- If `current < next` → **subtract** current (subtractive case)
- Otherwise → **add** current (normal case)

The "compare to the next character" check catches all subtractive
cases naturally, since a smaller symbol only appears before a larger
one specifically to signal subtraction.

## Code

```cpp
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> values = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int total = 0;

        for (int i = 0; i < s.size(); i++) {
            int current = values[s[i]];

            if (i + 1 < s.size() && current < values[s[i + 1]]) {
                total -= current;
            } else {
                total += current;
            }
        }

        return total;
    }
};
```

## Step-by-Step Trace

```
s = "IV"

i=0: current = values['I'] = 1
     next exists, values['V'] = 5
     1 < 5 -> subtract -> total = -1

i=1: current = values['V'] = 5
     no next character
     -> add -> total = -1 + 5 = 4

Result: 4
```

```
s = "MCMXCIV"   (= 1994)

i=0: M=1000, next C=100.  1000 < 100? No  -> add -> total=1000
i=1: C=100,  next M=1000. 100 < 1000? Yes -> sub -> total=900
i=2: M=1000, next X=10.   1000 < 10? No   -> add -> total=1900
i=3: X=10,   next C=100.  10 < 100? Yes   -> sub -> total=1890
i=4: C=100,  next I=1.    100 < 1? No     -> add -> total=1990
i=5: I=1,    next V=5.    1 < 5? Yes      -> sub -> total=1989
i=6: V=5,    no next      -> add -> total=1994

Result: 1994
```

## Key Insights

- This is hash map as a **lookup table** — fixed key-value pairs set
  up once, then only read from. No counting, no inserting during the
  loop, no existence-checking. A different flavor from all previous
  hash map problems.
- The condition `i + 1 < s.size()` guards against going out of bounds
  when checking the next character — the last character always gets
  added, never subtracted, since there's no "next" to compare it to.
- No special-casing of IV, IX, XL etc. is needed — the single
  `current < next` rule handles all subtractive pairs uniformly.

## Complexity

- **Time:** O(n) — one pass through the string, each lookup is O(1).
- **Space:** O(1) — the map holds exactly 7 entries regardless of
  input size.
