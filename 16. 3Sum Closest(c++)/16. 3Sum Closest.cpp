class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int result = nums[0]+nums[1]+nums[2];
        for(int i = 0; i < nums.size()-2; i++) {
            int j = i+1, k = nums.size()-1;
            while(j < k) {
                int tmp = nums[i]+nums[j]+nums[k];
                if(tmp == target) {
                    return target;
                }
                result = abs(tmp-target) > abs(result-target) ? result : tmp;
                tmp > target ? k-- : j++;
            }
        }
        return result;
    }
};