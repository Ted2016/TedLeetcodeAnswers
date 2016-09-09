class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx = nums.front(), cur = 0;
        for(auto num : nums) {
            cur = cur < 0 ? num : cur+num;
            mx = max(cur, mx);
        }
        return mx;
    }
};