class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) {
            return vector<int>{-1, -1};
        }
        int lhs = 0, rhs = nums.size();
        while(lhs < rhs) {
            int mid = lhs+(rhs-lhs)/2;
            if(nums[mid] == target){
                int left = mid-1, right = mid+1;
                while(left >= 0 && nums[left] == target) {
                    left--;
                }
                while(right < nums.size() && nums[right] == target) {
                    right++;
                }
                return vector<int>{left+1, right-1};
            } else if (nums[mid] > target) {
                rhs = mid;
            } else {
                lhs = mid+1;
            }
        }
        return vector<int>{-1, -1};
    }
};