class Solution {
public:
    int findMin(vector<int>& nums) {
        int lhs = 0, rhs = nums.size()-1;
        while(lhs != rhs) {
            if(nums[lhs] < nums[rhs]) {
                return nums[lhs];
            } 
            int mid = lhs + ((rhs-lhs)>>1);
            if (nums[mid] > nums[rhs]) {
                lhs = mid+1;
            } else {
                rhs = mid;
            }
        }
        return nums[lhs];
    }
    
};