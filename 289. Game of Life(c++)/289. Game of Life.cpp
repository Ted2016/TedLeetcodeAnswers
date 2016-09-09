class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> tmp = board;
        array<pair<int, int>, 8> check {make_pair(1, 0), make_pair(1, 1), make_pair(-1, 0)
            , make_pair(-1, 1), make_pair(0, 1), make_pair(0, -1), make_pair(-1, -1), make_pair(1, -1)
        }; 
        int size_i = tmp.size();
        for(int i = 0; i != size_i; i++) {
            int size_j = tmp[0].size(); 
            for(int j = 0; j != size_j; j++) {
                int tmp_i, tmp_j, total = 0;
                for(auto p : check) {
                    tmp_i = i + p.first;
                    tmp_j = j + p.second;
                    if(tmp_i >= 0 && tmp_i < size_i && tmp_j >= 0 && tmp_j < size_j && tmp[tmp_i][tmp_j] == 1) {
                        total++;
                    }
                }
                if(tmp[i][j] == 1 && (total < 2 || total > 3)) {
                     board[i][j] = 0;
                } else if (tmp[i][j] == 0 && total == 3){
                     board[i][j] = 1;
                }
            }
        }
    }
};