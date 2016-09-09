class Solution {
public:
    bool isPalindrome(string s) {
        int lhs = 0, rhs = s.size()-1;
        while(lhs < rhs) {
            while(lhs < rhs && !isalnum(s[lhs])) {
                lhs++;
            }
            while(lhs < rhs && !isalnum(s[rhs])) {
                rhs--;
            }
            if(lhs >= rhs) {
                break;
            }
            if(tolower(s[lhs]) != tolower(s[rhs])) {
                return false;
            }
            lhs++;
            rhs--;
        }
        return true;
    }
};