public class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> list = new ArrayList<Integer>();
        int sizeA = matrix.length;
        if(sizeA == 0) {
            return list;
        }
        int sizeB = matrix[0].length;
        int size = Math.min(sizeA, sizeB)>>1;
        for(int i = 0; i < size; i++) {
            int sizeInA = sizeA-1-i;
            int sizeInB = sizeB-1-i;
            for(int j = i; j < sizeInB; j++) {
                list.add(new Integer(matrix[i][j]));
            }
            for(int j = i; j < sizeInA; j++) {
                list.add(new Integer(matrix[j][sizeInB]));
            }
            for(int j = i; j < sizeInB; j++) {
                list.add(new Integer(matrix[sizeInA][sizeB-j-1]));
            }
            for(int j = i; j < sizeInA; j++) {
                list.add(new Integer(matrix[sizeA-j-1][i]));
            }
        }
        if(sizeA <= sizeB && sizeA%2 == 1) {
            for(int i = sizeA/2; i < sizeB-sizeA/2; i++) {
                list.add(new Integer(matrix[sizeA/2][i]));
            }
        } else if(sizeA > sizeB && sizeB%2 == 1) {
            for(int i = sizeB/2; i < sizeA-sizeB/2; i++) {
                list.add(new Integer(matrix[i][sizeB/2]));
            }
        }
        return list;
    }
}