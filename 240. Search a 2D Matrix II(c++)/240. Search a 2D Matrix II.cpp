class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return searchMatrix_help(matrix, target, 0, matrix.front().size()-1);
    }
    
    bool searchMatrix_help(vector<vector<int>>& matrix, int target, int x, int y) {
        if(x >= matrix.size() || y < 0) {
            return false;
        }
        int num = matrix[x][y];
        if(num == target) {
            return true;
        } else if(num > target) {
            return searchMatrix_help(matrix, target, x, y-1);
        } else {
            return searchMatrix_help(matrix, target, x+1, y);
        }
    }
};