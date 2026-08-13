class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;   // cheapest price seen so far
        int maxProfit = 0;        // best profit seen so far

        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];   // found a cheaper buy price
            } else {
                maxProfit = max(maxProfit, prices[i] - minPrice);   // would selling today beat best profit?
            }
        }

        return maxProfit;
    }
};
