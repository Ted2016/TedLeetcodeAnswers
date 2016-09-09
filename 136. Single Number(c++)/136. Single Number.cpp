class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for(int item : nums) {
            ret = ret^item;
        }
        return ret;
    }
};