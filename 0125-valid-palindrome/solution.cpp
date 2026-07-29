class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
 
        while (left < right) {
            // skip non-alphanumeric characters from the left
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            // skip non-alphanumeric characters from the right
            while (left < right && !isalnum(s[right])) {
                right--;
            }
 
            // compare characters, ignoring case
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
 
            left++;
            right--;
        }
 
        return true;
    }
};
