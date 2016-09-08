class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        for(int i = 0; i < obstacleGrid.size(); i++) {
            for(int j = 0; j < obstacleGrid[0].size(); j++) {
                if(obstacleGrid[i][j] == 0) {
                    obstacleGrid[i][j] = 1;
                } else {
                    obstacleGrid[i][j] = 0;
                }
            }
        }
        for(int i = 0; i < obstacleGrid[0].size(); i++) {
            if(obstacleGrid[0][i] == 0) {
                while(i < obstacleGrid[0].size()) {
                    obstacleGrid[0][i] = 0;
                    i++;
                }
            }
        }
        for(int i = 0; i < obstacleGrid.size(); i++) {
            if(obstacleGrid[i][0] == 0) {
                while(i < obstacleGrid.size()) {
                    obstacleGrid[i][0] = 0;
                    i++;
                }
            }
        }
        for(int i = 1; i < obstacleGrid.size(); i++) {
            for(int j = 1; j < obstacleGrid[0].size(); j++) {
                if(obstacleGrid[i][j] != 0) {
                    obstacleGrid[i][j] = obstacleGrid[i-1][j]+obstacleGrid[i][j-1];
                }
            }
        }
        return obstacleGrid.back().back();
    }
};

