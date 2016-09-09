class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int half_target = target>>1;
        for(int i = 1; i < numbers.size()+1 && numbers[i-1] <= half_target; i++) {
            int num = target-numbers[i-1];
            auto iter = lower_bound(numbers.begin()+i, numbers.end(), num);
            if(iter != numbers.end() && *iter == num) {
                return {i, iter-numbers.begin()+1};
            }
        }
        return {};
    }
};