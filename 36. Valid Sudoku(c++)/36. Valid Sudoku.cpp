class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<char> map(9, false);
        int size = board.size();
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                if(board[i][j] == '.'){
                    continue;
                }
                int n = board[i][j]-'1';
                if(!map[n]) {
                    map[n] = true;
                } else {
                    return false;
                }
            }
            map = vector<char>(9, false);
        }
        for(int i = 0; i < size; i++) {
            int i_pos = 3*(i/3), j_pos = 3*(i%3);
            for(int j = 0; j < size; j++) {
                int ti = i_pos + j/3, tj = j_pos + j%3;
                if(board[ti][tj] == '.'){
                    continue;
                }
                int n = board[ti][tj]-'1';
                if(!map[n]) {
                    map[n] = true;
                } else {
                    return false;
                }
            }
            map = vector<char>(9, false);
        }

        
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                if(board[j][i] == '.'){
                    continue;
                }
                int n = board[j][i]-'1';
                if(!map[n]) {
                    map[n] = true;
                } else {
                    return false;
                }
            }
            map = vector<char>(9, false);
        }
        return true;
        
    }
};