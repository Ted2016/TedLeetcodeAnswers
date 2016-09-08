class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> result{0};
        for(int i = 0; i < triangle.size(); i++) {
        	int size = triangle[i].size();
        	vector<int> tmp(size);
        	tmp[0] = triangle[i][0] + result.front();
        	tmp[size-1] = triangle[i][size-1] + result.back();
        	for(int j = 1; j < size-1; j++) {
        		tmp[j] = min(result[j-1], result[j])+triangle[i][j];
        	}
        	result = tmp;
        }
        return *min_element(result.begin(), result.end());
    }
};