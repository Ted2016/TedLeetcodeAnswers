public class Solution {
    public int minPathSum(int[][] grid) {
        int m = grid.length;
        if(m == 0) {
            return 0;
        }
        int n = grid[0].length;
        int[][] table = new int[m][n];
        table[0][0] = grid[0][0];
        for(int i = 1; i < m; i++) {
            table[i][0] = table[i-1][0]+grid[i][0];
        }
        for(int i = 1; i < n; i++) {
            table[0][i] = table[0][i-1]+grid[0][i];
        }
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                table[i][j] = grid[i][j]+Math.min(table[i-1][j], table[i][j-1]);
            }
        }
        return table[m-1][n-1];
    }
}