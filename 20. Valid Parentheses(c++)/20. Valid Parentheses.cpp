class Solution {
public:
    bool isValid(string s) {
        stack<int> stk;
        unordered_map<char, char> map{make_pair(')', '('), 
        make_pair(']', '['), make_pair('}', '{')};
        for(auto chr : s) {
            if(chr == ')' || chr == ']' || chr == '}') {
                if(stk.empty()) {
                    return false;
                } else {
                    auto item = stk.top();
                    stk.pop();
                    if(item != map[chr]) {
                        return false;
                    }
                }
            } else {
                stk.push(chr);
            }
        }
        if(stk.empty()) {
            return true;
        } else {
            return false;
        }
    }
};