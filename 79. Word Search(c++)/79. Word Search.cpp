class Solution {
public: 
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size() == 0)
            return true;
        int y_board = board.size();
        if(y_board == 0)
            return false;
        int x_board = board[0].size(); 
        for(int x = 0; x < x_board; x++) {
            for(int y = 0; y < y_board; y++) {
               if(Dfs(board, word, x, y, x_board, y_board))
                   return true;
            }   
        }   
        return false;  
        }
        
        bool Dfs(vector<vector<char>>& board, string& word, int x, int y, int x_board, int y_board) {
        if(word[0] != board[y][x])
            return false;
        int depth = 0, depth_max = word.size();
        if(depth_max == 1)
            return true;
        vector<int> word_vector(depth_max-1, -1);
        vector<vector<bool>> exist_board(y_board, vector<bool>(x_board, false));
        vector<int> x_change = {-1, 1, 1, -1};
        vector<int> y_change = {0, -1, 1, 1};
        depth++;
        word_vector[depth-1]++;
        exist_board[y][x] = true;
        x -= 1;
        while(depth > 0) {
            if(x < 0 || y < 0 || x >= x_board || y >= y_board || exist_board[y][x] == true ||
            (exist_board[y][x] == false && word[depth] != board[y][x])) {
                if(word_vector[depth-1] < 3) {
                    word_vector[depth-1]++;
                    x += x_change[word_vector[depth-1]];
                    y += y_change[word_vector[depth-1]];
                } else {
                          while (depth > 0 && word_vector[depth-1] == 3) {
                        word_vector[depth-1] = -1;
                        y -= 1;
                        exist_board[y][x] = false;
                        depth--;
                    }
                    if(depth > 0) {
                        word_vector[depth-1]++;
                        x += x_change[word_vector[depth-1]];
                        y += y_change[word_vector[depth-1]];
                    }
                     

                     
                }
                 
            }  else {
                depth++;
                exist_board[y][x] = true;
                if(depth < depth_max) {
                    word_vector[depth-1]++;
                    x += -1;
                } else {
                    return true;
                }
            }
        }
        return false;
    }
};
