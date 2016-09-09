class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto lhs = nums.begin(), rhs = lhs;
        int total = 0;
        while (rhs != nums.end()) {
            while(rhs != nums.end() && *rhs == val) {
                rhs++;
            }
            if(rhs == nums.end()) {
                break;
            }
            int tmp = *lhs;
            *lhs = *rhs;
            *rhs = tmp;
            rhs++;
            total++;
            lhs++;
        }
        return total;
    }
};