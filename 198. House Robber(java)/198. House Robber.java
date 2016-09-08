public class Solution {
    public int rob(int[] num) {
    int include = 0, exclude = 0;
    for (int j = 0; j < num.length; j++) {
        int i = include, e = exclude;
        include = e + num[j];
        exclude = Math.max(e, i);
    }
    return Math.max(include, exclude);
}
}