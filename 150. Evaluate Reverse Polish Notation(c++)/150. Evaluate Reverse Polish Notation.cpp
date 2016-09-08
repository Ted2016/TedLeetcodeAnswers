class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<string> operators{"+", "-", "*", "/"};
        stack<int> stk;
        for(auto iter = tokens.begin(); iter != tokens.end(); iter++) {
            if (find(operators.begin(), operators.end(), *iter) == operators.end()) {
                stk.push(atoi(iter->c_str()));
            } else {
                int rhs = stk.top();
                stk.pop();
                int lhs = stk.top(), n = 0;
                stk.pop();
                if(*iter == "+"){
                    n = lhs+rhs;
                } else if (*iter == "-"){
                    n = lhs-rhs;
                } else if (*iter == "*"){
                    n = lhs*rhs;
                } else {
                    n = lhs/rhs;
                }
                stk.push(n);
            }
        }
           
            
         
        return stk.top();
    }
};