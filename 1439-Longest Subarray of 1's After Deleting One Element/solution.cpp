class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int left = 0;
        int zeros = 0;
        int ans = 0;

        for (int right = 0; right < nums.size(); right++) {

            // Add the new element to our window
            if (nums[right] == 0) {
                zeros++;
            }

            // Too many zeros → shrink window
            while (zeros > 1) {
                if (nums[left] == 0) {
                    zeros--;
                }

                left++;
            }

            // One element must be deleted
            ans = max(ans, right - left);
        }

        return ans;
    }
};
