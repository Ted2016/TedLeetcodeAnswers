class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if(digits.empty()) {
            return ret;
        } 
        int curr = digits.back() - '0';
        vector<string> tmp = letterCombinations(string(digits.begin(), digits.end()-1));
        if(map[curr].empty()) {
            return tmp;
        }
        if(tmp.empty()) {
            for(auto i : map[curr]) {
                string str;
                str.push_back(i);
                ret.push_back(str);
            }
        } else {
             for(auto i : map[curr]) {
                transform(tmp.begin(), tmp.end(), back_inserter(ret), [i](const string& str)->string {
                    string new_str = str;
                    new_str.push_back(i);
                    return new_str;});
             }
        }
        return ret;
    }
private:
   vector<string> map {"", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"};
};