class Solution {
public:
    bool canJump(vector<int>& nums) {
        int position = nums.size()-1;
        for(int i = nums.size()-2; i >= 0; i--) {
            if(nums[i]+i >= position) {
                position = i;
            }
        }
        return position == 0;
    }
};