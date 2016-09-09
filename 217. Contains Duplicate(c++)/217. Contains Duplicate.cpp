class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(!nums.empty()) {
            unordered_map<int, int> hash;
            for(auto i : nums) {
               int n = ++hash[i];
               if(n > 1) {
                   return true;
               }
            }
        
        }
        return false;
        
    }
};