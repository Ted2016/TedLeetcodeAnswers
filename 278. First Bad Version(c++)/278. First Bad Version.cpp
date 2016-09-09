class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        auto lhs = nums.begin();
        auto iter = find_if(nums.begin(), nums.end(), [](int i) {return i != 0;});
        for(; iter != nums.end(); iter++) {
            if(0 != *iter) {
                int temp = *lhs^*iter;
                *lhs = temp^*lhs;
                *iter = temp^*iter;
                lhs++;
            }
        }
    }
};