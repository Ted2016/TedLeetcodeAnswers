public class Solution {
    public void setZeroes(int[][] matrix) {
        int sizeR = matrix.length;
        if(sizeR == 0) {
            return;
        }
        int sizeC = matrix[0].length;
        boolean Zero = false;
        for(int i = 0; i < sizeC; i++) {
            if(matrix[sizeR-1][i] == 0) {
                Zero = true;
                break;
            }

        }
        for(int i = 0; i < sizeR-1 ; i++) {
            boolean isZero = false;
            for(int j = 0; j < sizeC; j++) {
                if(matrix[i][j] == 0) {
                    matrix[sizeR-1][j] = 0;
                    isZero = true;
                }
            }
            if(isZero == true) {
                for(int j = 0; j < sizeC; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for(int i = 0; i < sizeC; i++) {
            if(matrix[sizeR-1][i] == 0) {
                for(int j = 0; j < sizeR; j++) {
                    matrix[j][i] = 0;
                }
            }

        }
        if(Zero == true) {
                for(int j = 0; j < sizeC; j++) {
                    matrix[sizeR-1][j] = 0;
                }
        }
    }
}
