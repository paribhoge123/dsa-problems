class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // Phase 1: all of nums1, duplicates automatically removed
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> result;

        // Phase 2: for each number in nums2, if it was also in nums1,
        // insert it into result (set insert handles uniqueness for us)
        for (int i = 0; i < nums2.size(); i++) {
            if (set1.count(nums2[i])) {
                result.insert(nums2[i]);
            }
        }

        // convert the result set back into a vector to return
        return vector<int>(result.begin(), result.end());
    }
};
