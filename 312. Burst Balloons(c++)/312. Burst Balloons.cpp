class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int size = nums.size();
        int map[size][size]  {};
        for(int n = 2; n < size; n++) {
            for(int lhs = 0; lhs < size-n; lhs++) {
                int rhs = lhs+n;
                for(int i = lhs+1; i < rhs; i++) {
                    map[lhs][rhs] = max(map[lhs][rhs], 
                    nums[lhs]*nums[i]*nums[rhs]+map[lhs][i]+map[i][rhs]);
                }
            }
        }
        return map[0][size-1];
    }
};






