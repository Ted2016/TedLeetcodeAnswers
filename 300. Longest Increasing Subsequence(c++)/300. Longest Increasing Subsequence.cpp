class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        if(nums.size() == 0) {
            return 0;
        }
        vector<int> vec{nums[0]};
        for(int i = 1; i < nums.size(); i++) {
            auto index = upper_bound(vec.begin(), vec.end(), nums[i]) - vec.begin();
            if(index == vec.size() && vec[index-1] != nums[i]) {
                vec.push_back(nums[i]);
            } else if (index == 0 || vec[index-1] != nums[i]){
                vec[index] = nums[i];
            }
        }
        return vec.size();
    }
};