class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret{};
        auto i = nums.cbegin();
        while(i != nums.cend()) {
            if(*i > 0) {
                break;
            } 
            auto j = i+1; 
            while(j != nums.cend()) {
                 int tmp = *i+*j;
                 if(tmp > 0) {
                   break;
                 } 
                 auto rest = find(j+1, nums.cend(), -tmp);
                 if(rest != nums.cend()) {
                     ret.push_back(vector<int>{*i, *j, *rest});
                 }
                 auto prev_j = j;
                 j++;
                 while(j != nums.cend() && *j == *prev_j) {
                     prev_j = j;
                     j++;
                 }
            }
            auto prev_i = i;
            i++;
            while(i != nums.cend() && *i == *prev_i) {
                prev_i = i;
                i++;
            }
        }
        return ret;
    }
};