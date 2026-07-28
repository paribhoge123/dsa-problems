class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            // swap s[left] and s[right] using a temp variable
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;

            // move pointers toward each other
            left++;
            right--;
        }
    }
};
