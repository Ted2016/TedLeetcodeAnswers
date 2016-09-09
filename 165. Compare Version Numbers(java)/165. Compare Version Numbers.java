public class Solution {
    public int compareVersion(String version1, String version2) {
        String[] strings1 = version1.split("\\.");
        String[] strings2 = version2.split("\\.");
        int i = 0, j = 0;
        while(i < strings1.length && j < strings2.length) {
            int num1 = Integer.parseInt(strings1[i]), num2 = Integer.parseInt(strings2[j]);
            if(num1 == num2) {
                i++;
                j++;
            } else if (num1 > num2) {
                return 1;
            } else {
                return -1;
            }
        }
        if(i == strings1.length && j == strings2.length) {
            return 0;
        } 
        String[] strings = strings1.length > strings2.length ? strings1 : strings2;
        boolean b = strings1.length > strings2.length ? true : false;
        while(i < strings.length) {
            int num = Integer.parseInt(strings[i]);
            if(num > 0) {
                return b ? 1 : -1;
            } else {
                i++;
            }
        }
        return 0;
    }
}