class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = 0;
        for(auto item : nums) {
            n ^= item; 
        }
        unsigned int test = 1;
        while (test != 0 ) {
            if(test&n) {
                break;
            }
            test = test << 1;
        }
        int x1 = 0, x2 = 0;
        for(auto item : nums) {
            if(item&test) {
                x1 ^= item;
            } else {
                x2 ^= item;
            }
        }
        return vector<int>{x1, x2};
    }
};