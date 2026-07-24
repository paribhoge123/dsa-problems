class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> m; // value -> index
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];

            if (m.count(complement))
            {
                ans.push_back(m[complement]);
                ans.push_back(i);
                return ans;
            }

            m[nums[i]] = i;
        }

        return ans;
    }
};
