class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result;
        if(strs.empty()) {
            return result;
        }
        result = strs.front();
        
        for(auto iter = strs.begin()+1; iter != strs.end(); iter++) {
            string str = *iter;
            size_t n = 0;
            while(n < str.size() && n < result.size()) {
                if(str[n] == result[n]) {
                    n++;
                } else {
                    break;
                }
            }
            result = string(result, 0, n);
        }
        return result;
    }
};