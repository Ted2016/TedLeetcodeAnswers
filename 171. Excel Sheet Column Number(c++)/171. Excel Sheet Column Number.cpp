class Solution {
public:
    int titleToNumber(string s) {
        int sum = 0;
        auto iter = s.cbegin();
        while(iter != s.cend()) {
            sum *= 26;
            sum += (*iter-'A')+1;
            iter++;
        }
        return sum;
    }
};