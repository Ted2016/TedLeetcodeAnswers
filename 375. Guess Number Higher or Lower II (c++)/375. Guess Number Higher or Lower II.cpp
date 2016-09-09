class Solution {
public:
    int getMoneyAmount(int n) {
        return dp(1, n);
    }    
    int dp( int lhs, int rhs) {
        if(lhs >= rhs ) {
            table[lhs][rhs] = 0;
            return 0;
        } else if (table[lhs][rhs] != -1){
            return table[lhs][rhs];
        } else {
            int result = INT_MAX;
            for(int i = lhs; i <= rhs; i++) {
                int tmp = i + max(dp(lhs, i-1), dp(i+1, rhs));
                result = min(result, tmp);
            }
            table[lhs-1][rhs-1] = result;
            return result;
        }
    }
private:
    array<array<int, 31>, 31> table(31, array<int, 31>(31, -1));
    
};
