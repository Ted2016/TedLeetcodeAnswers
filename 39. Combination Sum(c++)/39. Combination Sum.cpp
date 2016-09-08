class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        return combinationSum_recursive(candidates, target, 0);
    }
    
private:
    vector<vector<int>> combinationSum_recursive(vector<int>& candidates, int target, int pos) {
        int size = candidates.size();
        if(target == 0) {
            return vector<vector<int>>{vector<int>()};
        } else if(target < 0 || pos > size-1) {
            return vector<vector<int>>();
        }
        if(pos == size-1) {
            if(target%candidates[pos] == 0) {
                return vector<vector<int>>{vector<int>(target/candidates[pos], candidates[pos])};
            } else {
                return vector<vector<int>>();
            }
        }
        auto result1 = combinationSum_recursive(candidates, target-candidates[pos], pos);
        auto result2 =combinationSum_recursive(candidates, target, pos+1);
        for(auto &vec : result1) {
            vec.push_back(candidates[pos]);
        }
        result1.insert(result1.end(), result2.begin(), result2.end());
        return result1;
    }
};