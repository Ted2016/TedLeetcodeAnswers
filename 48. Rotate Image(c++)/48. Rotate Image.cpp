class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        auto size = matrix.size(), half_size = size%2 ? size/2+1 : size/2;
        for(int i = 0; i < half_size; i++) {
            for(int j = 0; j < half_size; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[size-j-1][i];
                matrix[size-j-1][i] = matrix[size-i-1][size-j-1];
                matrix[size-i-1][size-j-1] = matrix[j][size-i-1];
                matrix[j][size-i-1] = tmp;
            }
        }
    }
};