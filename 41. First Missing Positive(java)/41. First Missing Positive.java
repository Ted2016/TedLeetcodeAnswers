public class Solution {
    public int firstMissingPositive(int[] nums) {
        int length = nums.length;
        for(int i = 0; i < length; i++) {
            while(nums[i] > 0 && nums[i] <= length && nums[nums[i]-1] != nums[i] ) {
                int tmp = nums[nums[i]-1];
                nums[nums[i]-1] = nums[i];
                nums[i] = tmp;
            }
        }
        for(int i = 0; i < length; i++) {
            if(nums[i] != i+1) {
                return i+1;
            }
        }
        return length+1;
    }

}