class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        for(auto c : nums) {
            int temp = (a&~b&~c) + (~a&b&c);
            b = (~a&b&~c) + (~a&~b&c);
            a = temp;
        }
        return b;
    }
};