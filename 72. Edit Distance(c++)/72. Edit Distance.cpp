class Solution {
public:
    int minDistance(string word1, string word2) {
        int length1 = word1.size()+1, length2 = word2.size()+1;
        vector<vector<int>> dp(length1, vector<int>(length2, 0));
        //initialize the dynamic programing table
        for(int i = 1; i < length1; i++) {
            dp[i][0] += i;
        }
        for(int i = 1; i < length2; i++) {
            dp[0][i] += i;
        }
        //update the table
         for(int i = 1; i < length1; i++) {
            for(int j = 1; j < length2; j++) {
                //compare three cases which could possibly get the answer
                dp[i][j] = word1[i-1] == word2[j-1] ? dp[i-1][j-1] : dp[i-1][j-1]+1;
                dp[i][j] = min(dp[i][j], min(dp[i][j-1]+1, dp[i-1][j]+1));
            }
        }
        return dp[length1-1][length2-1];
    }
};