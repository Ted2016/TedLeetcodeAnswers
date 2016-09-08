class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> counts(3, 0);
        for(int num : nums) {
            counts[num]++;
        }
        int i = 0, begin = 0;
        for(int count : counts) {
            while(count-- > 0) {
                nums[i] = begin;
                i++;
            }
            begin++;
            
        }
    }
};