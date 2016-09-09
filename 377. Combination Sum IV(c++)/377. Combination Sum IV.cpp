class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        dp = vector<int>(target+1, -1);
        dp[0] = 1;
        return combinationSum4_help(nums, target);
    }
    
     int combinationSum4_help(vector<int>& nums, int target) {
        if(target < 0) {
            return 0;
        } else if(dp[target] != -1) {
            return dp[target];
        } else {
            int sum = 0;
            for(auto i : nums) {
                sum += combinationSum4_help(nums, target-i);
            }
            dp[target] = sum;
            return sum;
        }
    }
private:
    vector<int> dp;
};