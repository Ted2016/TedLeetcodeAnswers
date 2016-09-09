class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ret = 0;
        int size = nums.size();
        for(int i = 1; i < size+1; i++) {
            ret ^= i;
        }
        for(auto i : nums) {
            ret ^= i;
        }
        return ret;
    }
};