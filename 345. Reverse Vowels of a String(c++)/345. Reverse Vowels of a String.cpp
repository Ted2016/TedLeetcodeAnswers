class Solution {
public:
    string reverseVowels(string s) {
        if(s.empty() || s.size() == 1) {
            return s;
        }
        vector<char> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int lhs = 0, rhs = s.size()-1;
        while(lhs < rhs) {
            while(lhs < rhs && find(vowels.begin(), vowels.end(), s[lhs]) == vowels.end()) {
                lhs++;
            }
            if(lhs >= rhs) {
                break;
            }
            while(lhs < rhs && find(vowels.begin(), vowels.end(), s[rhs]) == vowels.end()) {
                rhs--;
            }
            if(lhs >= rhs) {
                break;
            }
            char tmp = s[lhs];
            s[lhs] = s[rhs];
            s[rhs] = tmp;
            lhs++;
            rhs--;
        }
        return s;
    }
};