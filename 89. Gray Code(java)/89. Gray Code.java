public class Solution {
    public List<Integer> grayCode(int n) {
        List<Integer> ints = new ArrayList<Integer>();
        ints.add(new Integer(0));
        for(int i = 1; i <= n; i++) {
            int mask = 1<<(i-1);
            for(int j = ints.size()-1; j >= 0; j--) {
                ints.add(new Integer(ints.get(j)|mask));
            }
        }
        return ints;
    }
}