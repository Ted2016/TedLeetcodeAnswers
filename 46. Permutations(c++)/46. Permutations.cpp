class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.empty()) {
            return result;
        }
        result.push_back(nums);
        int size = nums.size();
        for(int i = 1; i < size; i++) {
            int vec_size = result.size();
            for(int k = 0; k < vec_size; k++) {
                vector<int> vec = result[k];
                int tmp = vec[i-1];
                for(int j = i; j < size; j++) {
                    vec[i-1] = vec[j];
                    vec[j] = tmp;
                    result.push_back(vec);
                    vec[j] = vec[i-1];
                    vec[i-1] = tmp;
                }
            }
        }
        return result;
        
    }
};