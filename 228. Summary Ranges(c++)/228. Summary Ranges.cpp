class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if(nums.empty()) {
            return result;
        }
        int count = 0, prev = 0, i = 0;
        for(; i < nums.size(); i++) {
            if(count == 0 || nums[i] == prev+1) {
                count++;
            } else {
                string n = to_string(nums[i-count]);
                if(count == 1) {
                    result.push_back(n);
                } else {
                    result.push_back(n+"->"+to_string(prev));
                }
                count = 1;
            }
            prev = nums[i];
        }
        string n = to_string(nums[i-count]);
        if(count == 1) {
           result.push_back(n);
        } else {
           result.push_back(n+"->"+to_string(prev));         
        }
        return result;
    }
};