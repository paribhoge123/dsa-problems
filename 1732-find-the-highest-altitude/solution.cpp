class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int currentAltitude = 0;
        int maxAltitude = 0;   // starts at 0, since the trip's starting point is a valid answer

        for (int i = 0; i < gain.size(); i++) {
            currentAltitude += gain[i];

            if (currentAltitude > maxAltitude) {
                maxAltitude = currentAltitude;
            }
        }

        return maxAltitude;
    }
};
