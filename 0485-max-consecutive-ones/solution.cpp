class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;      // current streak of 1s
        int maxCount = 0;   // best streak seen so far

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                count++;
                maxCount = max(maxCount, count);
            }
            if (nums[i] == 0) {
                count = 0;   // streak breaks, reset current count
            }
        }

        return maxCount;
    }
};
