class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        string valid {'+', '-', '*'};
        vector<int> operands;
        vector<char> operators;
        for(int begin = 0; begin < input.length(); begin++) {
            auto cur = input.find_first_of(valid, begin);
            if(cur == string::npos) {
                operands.push_back(atoi(input.substr(begin, input.length()-begin).c_str()));
                break;
            }
            operands.push_back(atoi(input.substr(begin, cur-begin).c_str()));
            operators.push_back(input[cur]);
            begin = cur;
        }
        return diffWaysToCompute_recursive(operators, operands, 0, operators.size());
    }
    
    vector<int> diffWaysToCompute_recursive(const vector<char> &operators, const vector<int> &operands,int lhs, int rhs) {
        if(lhs == rhs) {
            return vector<int>{operands[lhs]};
        }
        vector<int> ints;
        for(int i = lhs; i < rhs; i++) {
           vector<int> left = diffWaysToCompute_recursive(operators, operands, lhs, i); 
           vector<int> right = diffWaysToCompute_recursive(operators, operands, i+1, rhs);
           for(int l = 0; l < left.size(); l++) {
               for(int r = 0; r < right.size(); r++) {
                   switch(operators[i]) {
                       case '+':
                           ints.push_back(left[l]+right[r]);
                           break;
                       case '-':
                           ints.push_back(left[l]-right[r]);
                           break;
                       case '*':
                           ints.push_back(left[l]*right[r]);
                   }
               }
           }
        }
        return ints;
    }
};