# LeetCode 392 — Is Subsequence

## Problem

Given two strings `s` and `t`, check whether `s` is a **subsequence** of `t`.

A subsequence means that the characters of `s` appear in `t` **in the same order**, but they do not have to be next to each other.

### Example

```text
Input:
s = "abc"
t = "ahbgdc"

Output:
true
```

`abc` appears in `ahbgdc` in the same order.

---

## Approach — Two Pointers

Use two pointers:

* `i` → points to the current character of `s`
* `j` → points to the current character of `t`

### Logic

1. Start both pointers at `0`.
2. Compare `s[i]` and `t[j]`.
3. If they are equal:

   * We found the required character.
   * Move `i`.
4. Always move `j` because we need to keep searching through `t`.
5. At the end:

   * If `i == s.length()`, every character of `s` was found.
   * Otherwise, `s` is not a subsequence.

---

## Code

```cpp
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;

        while (i < s.length() && j < t.length()) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }

        return i == s.length();
    }
};
```

---

## Dry Run

```text
s = "abc"
t = "ahbgdc"

        a h b g d c
        ↑
        j

s:
a
↑
i

a == a → i++, j++

        a h b g d c
          ↑
          j

a h b g d c
  ↑
  i

b != h → j++

        a h b g d c
            ↑
            j

a b c
  ↑
  i

b == b → i++, j++

Continue...

c == c → i++
```

At the end:

```text
i == s.length()
```

Therefore:

```text
true
```

---

## Complexity

* **Time:** `O(n)` — we scan through `t` once.
* **Space:** `O(1)` — only two pointers are used.

---

## Key Pattern to Remember

### Two Pointers — One String Is Being Searched

When checking whether one sequence appears inside another **in order**, think:

```text
i → smaller/required string
j → larger/search string
```

If characters match:

```cpp
i++;
```

Always:

```cpp
j++;
```

Finally:

```cpp
return i == s.length();
```

### Pattern

```cpp
int i = 0, j = 0;

while (i < s.length() && j < t.length()) {
    if (s[i] == t[j]) {
        i++;
    }
    j++;
}

return i == s.length();
```

---

## Important Edge Cases

### Empty `s`

```text
s = ""
t = "abc"

Answer = true
```

An empty string is a subsequence of every string.

### `s` longer than `t`

```text
s = "abcd"
t = "abc"

Answer = false
```

There aren't enough characters to form `s`.

---

## What I Learned

The main idea is **not to move both pointers together**.

`j` explores the entire `t`, while `i` only moves when we find the next required character.

> **Search with `j`, match with `i`.**
