class Solution {
private:
    vector<int> dp;
public:
    int numSquares(int n) {
        dp = vector<int>(n+1, INT_MAX);
        for(int i = 1; i*i <= n; i++) {
            dp[i*i] = 1;
        }
        return recursive(n);
    }
    
    int recursive(int n) {
        if(dp[n] != INT_MAX) {
            return dp[n];
        } 
        for(int i = 1; i*i < n; i++) {
            dp[n] = min(recursive(n-i*i)+1, dp[n]);
        }
        return dp[n];
    }
};