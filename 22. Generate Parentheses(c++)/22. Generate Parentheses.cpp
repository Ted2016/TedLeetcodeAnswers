class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n+1);
        dp[0] = vector<string>{""};
        if(n == 0) {
            return dp[0];
        }
        dp[1] = vector<string>{"()"};
        for(int i = 2; i <= n; i++) {
            vector<string> strs;
            for(int j = 0; j < i; j++) {
                string str;
                for(const auto & item1 : dp[j]) {
                    str = "(" + item1 + ")";
                    for(const auto & item2 : dp[i-j-1]) {
                        strs.push_back(str+item2);
                    }
                }
            }
            dp[i] = strs;
        }
        return dp[n];
    }
};