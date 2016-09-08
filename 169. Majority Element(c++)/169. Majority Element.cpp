class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = (nums.cend()-nums.cbegin())/2;
        return *(nums.begin()+n);
    }
};