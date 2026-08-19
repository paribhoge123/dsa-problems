class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        // Phase 1: build first window sum
        double windowSum = 0;
        for (int i = 0; i < k; i++) {
            windowSum += arr[i];
        }

        int count = 0;
        if (windowSum / k >= threshold) count++;

        // Phase 2: slide the window
        for (int i = k; i < arr.size(); i++) {
            windowSum += arr[i];
            windowSum -= arr[i - k];
            if (windowSum / k >= threshold) count++;
        }

        return count;
    }
};
