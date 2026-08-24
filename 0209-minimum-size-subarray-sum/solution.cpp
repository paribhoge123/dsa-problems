class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int windowSum = 0;
        int minLen = INT_MAX;   // start at largest possible, shrink down

        for (int right = 0; right < nums.size(); right++) {
            windowSum += nums[right];   // expand window from right

            while (windowSum >= target) {
                minLen = min(minLen, right - left + 1);   // record current window size
                windowSum -= nums[left];                   // shrink from left
                left++;
            }
        }

        // if minLen was never updated, no valid subarray exists
        return minLen == INT_MAX ? 0 : minLen;
    }
};
