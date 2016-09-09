class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if(numRows == 0) {
            return result;
        }
        vector<int> ints{1};
        result.push_back(ints);
        for(int i = 1; i < numRows; i++) {
            vector<int> tmp{1};
            for(int j = 1; j < ints.size(); j++) {
                tmp.push_back(ints[j-1]+ints[j]);
            }
            tmp.push_back(1);
            ints = tmp;
            result.push_back(ints);
        }
        return result;
    }
};