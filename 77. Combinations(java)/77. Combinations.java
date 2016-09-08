public class Solution {
    public List<List<Integer>> combine(int n, int k) {

    
        return combine_help(n, k, 1);
    }
    private List<List<Integer>> combine_help(int n, int k, int begin) {
        List<List<Integer>> list = new ArrayList<List<Integer>>();
        if(k == 0) {
            List<Integer> tmp = new ArrayList<Integer>();
            list.add(tmp);
            return list;
        }
        int limit = n-k+1;
        for(int i = begin; i <= limit; i++) {
            List<List<Integer>> tmp = combine_help(n, k-1, i+1);
            for(List<Integer> l : tmp) {
                l.add(i);
            }
            list.addAll(tmp);
        }
        return list;
    }
}
