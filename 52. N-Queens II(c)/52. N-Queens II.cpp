#define INITIAL -99

int isValid(int* position ,int row, int column);

int totalNQueens(int n) {
     int row = 0, column = 0;
    int position[n];
    for(int i = 0; i < n; i++) {
        position[i] = INITIAL;
    }
  
    int ret = 0;
    while (row < n) {
        while(column < n) {
            if(isValid(position, row, column)) {
                position[row] = column;
                column = 0;
                break; 
            } else 
                column++;
        }       
        
        
        if(position[row] == INITIAL) {
            if(row == 0)
                return ret;
            else {
               row--;
               column = position[row]+1;
               position[row] = INITIAL;
               continue;
            }
        }
        
        if(n-1 == row) {
            ret++;
            
            column = position[n-1] + 1;
            position[n-1] = INITIAL;
            continue;
        }

        row++;
    }

}

int isValid(int* position ,int row, int column) {
    int i = 0;
    while(i < row) {
        if(position[i] == column || abs(position[i]-column) == abs(row-i))
            return 0;
        i++;        
    }
    return 1;
}