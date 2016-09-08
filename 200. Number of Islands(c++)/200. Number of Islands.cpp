class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()) {
            return 0;
        }
        int num = 0;
        vector<vector<bool>> visit(grid.size(), vector<bool>(grid[0].size(), false));
        int factors[4][2]{{0, 1}, {0, -1}, {1, 0},{-1, 0}};
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(visit[i][j] || grid[i][j] == '0') {
                    continue;
                } 
                visit[i][j] = true;
                num++;
                deque<pair<int, int>> que{make_pair(i, j)};
                while(!que.empty()) {
                    auto tmp = que.front();
                    que.pop_front();
                    int x = tmp.first, y = tmp.second;
                    for(int k = 0; k < 4; k++) {
                        x += factors[k][0];
                        y += factors[k][1];
                        if(x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == '1' && !visit[x][y]) {
                             que.push_back(make_pair(x, y));
                             visit[x][y] = true;
                        }
                        x -= factors[k][0];
                        y -= factors[k][1];
                    }
                }
            }
        }
        return num;
    }
};