public class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        result.add(new ArrayList<Integer>());
        for(int i = 0; i < nums.length; i++) {
        	int length = result.size();
        	for(int j = 0; j < length; j++) {
        		List<Integer> tmp = new ArrayList<Integer>();
        		tmp.addAll(result.get(j));
        		tmp.add(new Integer(nums[i]));
        		result.add(tmp);
        	}
        }
        return result;
    }
}