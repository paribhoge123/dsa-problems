class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> values = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int total = 0;

        for (int i = 0; i < s.size(); i++) {
            int current = values[s[i]];

            // if there's a next character, and it's bigger than current, subtract
            if (i + 1 < s.size() && current < values[s[i + 1]]) {
                total -= current;
            } else {
                total += current;
            }
        }

        return total;
    }
};
