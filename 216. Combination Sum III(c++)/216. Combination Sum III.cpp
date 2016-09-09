class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        return combinationSum3_help(k, n, 0);
    }
    
    vector<vector<int>> combinationSum3_help(int k, int n, int c) {
        if(k > 9-c || k <= 0 || c >= 9 || n < c+1) {
            return vector<vector<int>>{};
        } else if( n == c+1 && k == 1) {
            return vector<vector<int>>{vector<int>{c+1}};
        }
        vector<vector<int>> resultA = combinationSum3_help(k-1, n-c-1, c+1);
        for_each(resultA.begin(), resultA.end(), [c](vector<int>& vct) {
            vct.insert(vct.begin(), c+1);
        } );
        vector<vector<int>> resultB = combinationSum3_help(k, n, c+1);
        resultA.insert(resultA.end(), resultB.begin(), resultB.end());
        return resultA;
    }
};