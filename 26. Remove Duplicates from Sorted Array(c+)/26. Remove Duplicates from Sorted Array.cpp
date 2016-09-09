class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto iter = unique(nums.begin(), nums.end());
        return iter - nums.begin();
    }
};