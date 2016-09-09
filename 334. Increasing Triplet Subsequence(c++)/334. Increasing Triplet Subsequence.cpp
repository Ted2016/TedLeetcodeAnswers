class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.empty()) {
            return false;
        }
        vector<int> result{nums[0]};
        for(int i = 1; i < nums.size(); i++) {
            auto iter = upper_bound(result.begin(), result.end(), nums[i]);
            if(iter != result.begin() && *(iter-1) == nums[i]) continue;
            if(iter == result.end()) {
                result.push_back(nums[i]);
            } else {
                *iter = nums[i];
            }
            if(result.size() == 3) {
                return true;
            }
        }
        return false;
    }
};