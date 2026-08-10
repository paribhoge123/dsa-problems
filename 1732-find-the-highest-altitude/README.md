# 1732. Find the Highest Altitude

**Link:** https://leetcode.com/problems/find-the-highest-altitude/
**Difficulty:** Easy
**Approach:** Running total + track best-so-far (combines two earlier patterns)
**Time:** O(n)   **Space:** O(1)

## Problem

A biker starts at altitude `0` and travels along `n` segments given by
array `gain`, where `gain[i]` is the net altitude change of segment
`i`. Return the highest altitude reached at any point during the
trip.

## Idea

This combines two patterns already practiced separately:

1. **Running total** (same idea as Running Sum of 1d Array) — keep
   adding each `gain[i]` to a running altitude as you go.
2. **Track the best so far** (same idea as finding a max element) —
   at every step, check if the current altitude beats the best seen
   so far, and update if it does.

`maxAltitude` starts at `0` (not the first computed altitude),
because the biker's actual starting point — altitude `0` — is itself
a valid candidate for the answer. If every `gain` value were
negative, the highest point reached would be the start itself.

## Code

```cpp
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int currentAltitude = 0;
        int maxAltitude = 0;

        for (int i = 0; i < gain.size(); i++) {
            currentAltitude += gain[i];

            if (currentAltitude > maxAltitude) {
                maxAltitude = currentAltitude;
            }
        }

        return maxAltitude;
    }
};
```

## Step-by-Step Trace

```
gain = [-5, 1, 5, 0, -7]
currentAltitude=0, maxAltitude=0

i=0: currentAltitude = -5.  -5 > 0? No.
i=1: currentAltitude = -4.  -4 > 0? No.
i=2: currentAltitude = 1.   1 > 0? Yes -> maxAltitude = 1
i=3: currentAltitude = 1.   1 > 1? No.
i=4: currentAltitude = -6.  -6 > 1? No.

Result: 1
```

## Key Insights

- Genuinely just two already-known patterns stacked together in one
  loop: accumulate a running value, and separately track the best
  value seen so far — no new concept required.
- The starting value for `maxAltitude` matters and depends on
  context: here it's `0` (a real, reachable altitude before any
  gain is applied), whereas in a plain "find max of an array"
  problem, the safe starting value is the array's own first element
  — using an arbitrary guess (like `-1` or `0` in that case) can
  silently produce a wrong answer if it's never legitimately beaten.

## Complexity

- **Time:** O(n) — one pass through `gain`.
- **Space:** O(1) — two running variables, no extra storage.
