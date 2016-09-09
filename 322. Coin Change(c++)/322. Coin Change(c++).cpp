class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1, amount +1);

        if (amount == 0)
            return 0;
        if (amount < 0)
            return -1;

        sort(coins.begin(), coins.end());

        dp[0] = 0;

        for (int cur_amount = 1; cur_amount <= amount; cur_amount++)
        {
            for (int i = 0; i < n && cur_amount >= coins[i]; i++)
            {
                int temp = dp[cur_amount - coins[i]] + 1;

                if (dp[cur_amount] > temp)
                    dp[cur_amount] = temp;
            }
        }
        if (dp[amount] == (amount + 1))
            return -1;

        return dp[amount];
    }
};