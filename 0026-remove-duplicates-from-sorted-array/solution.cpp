class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0;   // tracks position of last unique element written

        for (int fast = 1; fast < nums.size(); fast++) {
            if (nums[fast] != nums[slow]) {
                slow++;
                nums[slow] = nums[fast];   // overwrite, no swap needed
            }
        }

        return slow + 1;   // slow is 0-indexed, +1 gives the count
    }
};
