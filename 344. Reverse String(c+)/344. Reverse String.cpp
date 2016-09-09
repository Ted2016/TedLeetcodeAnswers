class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) {
            return 1;
        } else if (n == 3) {
            return 2;
        }
        int count = n/3, mod = n%3;
        if (mod == 0) {
            return pow(3, count);
        } else if (mod == 1) {
            return pow(3, count-1)*4;
        } else {
            return pow(3, count)*2;
        }
    }
};