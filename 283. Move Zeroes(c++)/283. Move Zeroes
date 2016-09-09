class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size == 0) {
            return 0;
        } else if(size == 1 || size == 2 || size == 3) {
            return *max_element(nums.begin(), nums.end());
        }
        vector<vector<int>> dp = vector<vector<int>>(size-3, vector<int>(size, 0));
        for(int i = 0; i < size-3; i++) {
            for(int j = 0; j < size; j++) {
                int maxVal = 0;
                for(int k = 0; k <= i; k++) {
                    int lhs = 0, rhs = 0;
                    if(k >= 2) {
                       lhs = dp[k-2][j]; 
                    }
                    if(k <= i-2) {
                        rhs = dp[i-2-k][(j+k+2)%size];
                    }
                    maxVal = max(maxVal, nums[(j+k)%size]+lhs+rhs);
                    dp[i][j] = maxVal;
                }
            }
        }
        int ret = 0;
        for(int i = 0; i < size; i++) {
            ret = max(ret, nums[i]+dp[size-4][(i+2)%size]);
        }
        return ret;
    }
};