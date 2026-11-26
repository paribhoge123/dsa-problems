# LeetCode 50 — Pow(x, n)

## Problem

Implement `pow(x, n)`, which calculates `x` raised to the power `n` (i.e., `xⁿ`).

**Constraints:**
- `-100.0 < x < 100.0`
- `-2³¹ <= n <= 2³¹ - 1`
- `n` is an integer
- Either `x` is not zero or `n > 0`

---

## Approach — Binary Exponentiation (Fast Power)

Instead of multiplying `x` by itself `n` times (brute force O(n)), this solution uses the **binary representation of `n`** to compute the result in **O(log n)** time.

### Core Idea

Any exponent can be expressed as a sum of powers of 2 (binary):

```
13 = 1101₂ = 8 + 4 + 1

So: x^13 = x^8 × x^4 × x^1
```

We iterate through each bit of `n`. At every step:
- `x` is **squared** (moves to the next power of 2)
- If the current bit is `1`, we **multiply `x` into the answer**

---

## Solution (C++)

```cpp
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1.0;
        if(x == 0) return 0.0;
        if(x == 1) return 1.0;
        if(x == -1 && n%2 == 0) return 1.0;
        if(x == -1 && n%2 != 0)  return -1.0;

        long binForm = n;
        if(n < 0){
            x = 1/x;
            binForm = -binForm;
        }

        double ans = 1;

        while(binForm > 0){
            if(binForm % 2 == 1){
                ans *= x;
            }
            x *= x;
            binForm /= 2;
        }
        return ans;
    }
};
```

---

## Step-by-Step Explanation

### 1. Edge Cases

| Condition | Return | Reason |
|---|---|---|
| `n == 0` | `1.0` | Anything to the power 0 is 1 |
| `x == 0` | `0.0` | 0 to any power is 0 |
| `x == 1` | `1.0` | 1 to any power is 1 |
| `x == -1, n even` | `1.0` | Negative base with even exponent is positive |
| `x == -1, n odd` | `-1.0` | Negative base with odd exponent is negative |

### 2. Negative Exponent Handling

```cpp
long binForm = n;   // use long to avoid INT_MIN overflow
if(n < 0){
    x = 1/x;        // x^(-n) = (1/x)^n
    binForm = -binForm;
}
```

> `long` is used because negating `INT_MIN` overflows a 32-bit `int`.

### 3. Binary Exponentiation Loop

```
Trace for x^13  (13 = 1101 in binary, read right to left → 1, 0, 1, 1)

┌────────┬─────────┬────────┬──────────────────┬──────┐
│  Iter  │ binForm │  bit   │       ans        │  x   │
├────────┼─────────┼────────┼──────────────────┼──────┤
│   1    │   13    │   1  ✓ │ 1 × x¹  =  x¹   │  x²  │
│   2    │    6    │   0  ✗ │ x¹ (unchanged)   │  x⁴  │
│   3    │    3    │   1  ✓ │ x¹ × x⁴ =  x⁵   │  x⁸  │
│   4    │    1    │   1  ✓ │ x⁵ × x⁸ =  x¹³  │  x¹⁶ │
│   5    │    0    │  STOP  │    x¹³  ✅       │      │
└────────┴─────────┴────────┴──────────────────┴──────┘
```

---

## Complexity Analysis

| | Complexity |
|---|---|
| **Time** | O(log n) |
| **Space** | O(1) |

**Why O(log n)?** The number of bits in `n` is `log₂(n)`, so the while loop runs at most `log₂(n)` times — far better than the naive O(n) approach.

---

## Example Walkthrough

```
Input:  x = 2.0, n = 10
Binary: 10 = 1010₂

Iter 1: bit=0 → skip,  x = 4.0,   ans = 1
Iter 2: bit=1 → take,  x = 16.0,  ans = 4
Iter 3: bit=0 → skip,  x = 256.0, ans = 4
Iter 4: bit=1 → take,  x = ...,   ans = 4 × 256 = 1024

Output: 1024.0 ✅
```

---

## Key Takeaway

> Binary Exponentiation works by decomposing `x^n` into a product of `x^(powers of 2)`, reading the bits of `n` one by one. It is one of the most fundamental algorithms in competitive programming.
