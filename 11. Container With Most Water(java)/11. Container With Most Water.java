public class Solution {
    public int maxArea(int[] height) {
        int lhs = 0, rhs = height.length-1;
        int maxA = 0;
        while(lhs < rhs) {
            maxA = Math.max(maxA, (rhs-lhs)*Math.min(height[lhs], height[rhs]));
            if(height[lhs] > height[rhs]) {
                rhs--;
            } else {
                lhs++;
            }
        }
        return maxA;
    }
}