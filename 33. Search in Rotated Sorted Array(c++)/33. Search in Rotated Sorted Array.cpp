class Solution {
public:
    int search(vector<int>& nums, int target) {
        return search_help(nums, nums.cbegin(), nums.cend(), target);
    }
    int search_help(vector<int>& nums, vector<int>::const_iterator lhs, 
    vector<int>::const_iterator rhs, int target) {
        if(lhs == rhs) {
            return -1;
        } else if(*lhs <= *(rhs-1)) {
            auto iter = lower_bound(lhs, rhs, target);
            if(iter == rhs || *iter != target) {
                return -1;
            } else {
                return iter-nums.cbegin();
            }
        } else {
            int mid = (rhs-lhs)>>1;
            if(*(lhs+mid) == target) {
                return lhs+mid-nums.cbegin();
            } else {
                return max(search_help(nums, lhs, lhs+mid, target),
                search_help(nums, lhs+mid+1, rhs, target));
            }
            
        }
        
    }
};