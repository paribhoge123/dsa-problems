class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // Phase 1: build the first window sum
        double windowSum = 0;
        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }

        double maxSum = windowSum;

        // Phase 2: slide the window one step at a time
        for (int i = k; i < nums.size(); i++) {
            windowSum += nums[i];       // add new element coming in (right side)
            windowSum -= nums[i - k];   // remove old element going out (left side)
            maxSum = max(maxSum, windowSum);
        }

        return maxSum / k;
    }
};
