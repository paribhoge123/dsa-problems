class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        // Step 1: Create a hash map to store character frequencies
        unordered_map<char, int> mp;

        // Step 2: Count each character in the magazine
        for (char ch : magazine) {
            mp[ch]++;
        }

        // Step 3: Check each character of the ransom note
        for (char ch : ransomNote) {

            // If character doesn't exist OR its count is 0
            if (mp[ch] == 0) {
                return false;
            }

            // Use one occurrence of that character
            mp[ch]--;
        }

        // Step 4: If all characters were found
        return true;
    }
};
