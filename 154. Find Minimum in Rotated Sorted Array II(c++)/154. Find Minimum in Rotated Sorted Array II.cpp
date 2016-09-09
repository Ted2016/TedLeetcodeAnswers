class Solution {
public:
    int findMin(vector<int>& nums) {
        return findMinRecur(nums, 0, nums.size());
    }
    int findMinRecur(vector<int>& nums, int lhs, int rhs) {
        if(lhs == rhs-1) {
            return nums[lhs];
        } else if(lhs == rhs-2) {
            return min(nums[lhs], nums[lhs+1]);
        }
        int mid = lhs+((rhs-lhs)>>1);
        if(nums[mid] < nums[mid-1]) {
            return nums[mid];
        } else if(nums[mid] > nums[mid+1]) {
            return nums[mid+1];
        } else {
            return min(findMinRecur(nums, lhs, mid),  findMinRecur(nums, mid, rhs));
        }
    }
};