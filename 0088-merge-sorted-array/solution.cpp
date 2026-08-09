class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1;          // last real element in nums1
        int p2 = n - 1;          // last element in nums2
        int p = m + n - 1;       // last open slot in nums1

        while (p1 >= 0 && p2 >= 0) {
            if (nums1[p1] > nums2[p2]) {
                nums1[p] = nums1[p1];
                p1--;
            } else {
                nums1[p] = nums2[p2];
                p2--;
            }
            p--;
        }

        // if nums2 still has leftover (smaller) elements, copy them in.
        // if p1 still has leftover elements instead, they're already
        // sitting in the correct place, so nothing more needs to happen.
        while (p2 >= 0) {
            nums1[p] = nums2[p2];
            p2--;
            p--;
        }
    }
};
