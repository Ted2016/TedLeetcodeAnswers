class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int lhs = 0, rhs = nums.size()-1;
        while(lhs < rhs) {
            int mid = lhs+((rhs-lhs)>>1);
            if(mid == 0) {
                return nums[mid] > nums[mid+1] ? mid : mid+1;
            } 

            if(nums[mid] > nums[mid+1] && nums[mid] > nums[mid-1]) {
                return mid;
            } else if(nums[mid] > nums[mid+1] && nums[mid] < nums[mid-1]) {
                rhs = mid;
            } else {
                lhs = mid+1;
            }
        }
        return lhs;
    }
};


