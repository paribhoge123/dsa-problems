class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowels = {'a','e','i','o','u'};

        // Phase 1: count vowels in first window
        int count = 0;
        for (int i = 0; i < k; i++) {
            if (vowels.count(s[i])) count++;
        }

        int maxCount = count;

        // Phase 2: slide the window
        for (int i = k; i < s.size(); i++) {
            if (vowels.count(s[i]))   count++;   // new character entering
            if (vowels.count(s[i-k])) count--;   // old character leaving
            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};
