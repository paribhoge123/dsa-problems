class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
 
        // Step 1: count occurrences of each number
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }
 
        // Step 2: find the key with the highest count
        int maxCount = 0;
        int answer = -1;
 
        for (auto p : m) {
            if (p.second > maxCount) {
                answer = p.first;
                maxCount = p.second;
            }
        }
 
        return answer;
    }
};