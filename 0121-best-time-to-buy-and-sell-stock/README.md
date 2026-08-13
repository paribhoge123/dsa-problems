# 121. Best Time to Buy and Sell Stock

**Link:** https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
**Difficulty:** Easy
**Approach:** Single pass — track minimum price + maximum profit
**Time:** O(n)   **Space:** O(1)

## Problem

Given an array `prices` where `prices[i]` is the stock price on day
`i`, return the maximum profit from buying on one day and selling on
a later day. Return `0` if no profit is possible.

## Idea

The naive approach — try every buy/sell pair — is O(n²). Instead,
use the same "track current + track best" pattern from Max
Consecutive Ones and Find the Highest Altitude, applied here to two
running values simultaneously:

- **`minPrice`** — the cheapest price seen so far (best day to have
  bought). Updated whenever a lower price is found.
- **`maxProfit`** — the best profit seen so far. Updated whenever
  selling today (`prices[i] - minPrice`) beats the current best.

One single pass, two independent running values — no nested loop,
no re-scanning from scratch at each day.

`INT_MAX` is used as the starting `minPrice` — the largest possible
`int` value — so the very first price always becomes the initial
minimum naturally, without needing a special case.

## Code

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            } else {
                maxProfit = max(maxProfit, prices[i] - minPrice);
            }
        }

        return maxProfit;
    }
};
```

## Step-by-Step Trace

```
prices = [7, 1, 5, 3, 6, 4]   minPrice=INT_MAX, maxProfit=0

Day 0: price=7.  7 < INT_MAX -> minPrice=7
Day 1: price=1.  1 < 7       -> minPrice=1
Day 2: price=5.  5 < 1? No   -> profit=5-1=4,  maxProfit=4
Day 3: price=3.  3 < 1? No   -> profit=3-1=2,  maxProfit=4
Day 4: price=6.  6 < 1? No   -> profit=6-1=5,  maxProfit=5
Day 5: price=4.  4 < 1? No   -> profit=4-1=3,  maxProfit=5

Result: 5  (buy day 1 at price 1, sell day 4 at price 6)
```

## Key Insights

- You never need to go back and re-scan — at any point, `minPrice`
  already holds the best possible buy price for everything seen so
  far. So subtracting it from today's price instantly gives the best
  possible profit if you sold today.
- The `if/else` structure works correctly here: if today's price is
  a new minimum, the "profit" would be zero (buy and sell same day),
  which never beats `maxProfit` — so checking profit only in the
  `else` branch is safe and correct.
- `INT_MAX` as a starting value is a common C++ pattern for
  "track the minimum" problems — guarantees the first real value
  always wins the first comparison.

## Complexity

- **Time:** O(n) — one pass through the prices array.
- **Space:** O(1) — only two running variables used.
