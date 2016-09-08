class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }
        int lhs = 1, rhs = 1;
        int count = 1, prev = nums[0];
        while(rhs < nums.size()) {
            int tmp = nums[rhs];
            if(nums[rhs] == prev && count < 2) {
                std::iter_swap(nums.begin()+rhs, nums.begin()+lhs);
                lhs++;
                count++;
            } else if(nums[rhs] != prev){
                std::iter_swap(nums.begin()+rhs, nums.begin()+lhs);
                lhs++;
                count = 1;
            } 
            rhs++;
            prev = tmp;
        }
        return lhs;
    }
};