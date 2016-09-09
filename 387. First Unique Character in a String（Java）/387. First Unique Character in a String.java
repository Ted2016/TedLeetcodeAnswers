public class Solution {
    public int firstUniqChar(String s) {
        int[] ints = new int[26];
        boolean[] bools = new boolean[26];
        Arrays.fill(bools, false);
        char[] chars = s.toCharArray();
        for(char c : chars) {
            ints[c-'a']++;
        }
        for(int i = 0; i < chars.length; i++) {
            int pos = chars[i]-'a';
            if(bools[pos] == false ) {
                if(ints[pos]-- == 1) {
                    return i;
                } 
                bools[pos] = true;
            }
        }
        return -1;
      
    }
}