class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        int size = n/2, cur = 1;
        for(int i = 0; i < size; i++) {
            int num = n-i-1;
            for(int j = i; j < num; j++) {
                result[i][j] = cur;
                cur++;
            }
            for(int j = i; j < num; j++) {
                result[j][num] = cur;
                cur++;
            }
            for(int j = i; j < num; j++) {
                result[num][n-j-1] = cur;
                cur++;
            }
            for(int j = i; j < num; j++) {
                result[n-j-1][i] = cur;
                cur++;
            }
        }
        if(n%2){
            result[size][size] = cur;
        }
        return result;
    }
};