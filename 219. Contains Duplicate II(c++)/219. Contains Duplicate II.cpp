class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        int size = nums.size();
        int n = min(k+1, size);
        for(int i = 0; i < n; i++) {
            if(hash.find(nums[i]) == hash.end()) {
                hash[nums[i]]++;
            } else {
                return true;
            }
        }
        
        for(int i = n; i < size; i++) {
            hash[nums[i-n]]--;
            if(hash[nums[i]]++ != 0) {
                return true;
            } 
        }
        return false;
        
    }
};