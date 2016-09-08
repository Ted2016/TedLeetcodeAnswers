class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1) {
            return 0;
        }
        auto p = minmax_element(nums.begin(), nums.end());
        int Min = *p.first, Max = *p.second;
        int gap = ceil(static_cast<double>(Max-Min)/(nums.size()-1));
        if(gap == 0){
            return 0;
        }
        int bucket_size = ceil(static_cast<double>(Max-Min)/gap);
        vector<int> max_bucket(bucket_size, INT_MIN);
        vector<int> min_bucket(bucket_size, INT_MAX);
        for(int num : nums){
            if(num == Max || num == Min) {
                continue;
            }
            int pos = (num-Min)/gap;
            max_bucket[pos] = max(max_bucket[pos], num);
            min_bucket[pos] = min(min_bucket[pos], num);
        }
        int max_gap = gap, tmp = Min;
        for(int i = 0; i < bucket_size; i++) {
            if(max_bucket[i] == INT_MIN) {
                continue;
            }
            max_gap = max(max_gap, min_bucket[i]-tmp);
            tmp = max_bucket[i];
        }
        max_gap = max(max_gap, Max-tmp);
        return max_gap;
    }
};