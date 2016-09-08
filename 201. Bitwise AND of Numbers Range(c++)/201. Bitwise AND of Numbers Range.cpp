class Solution {
private:
    int log2(int n) {
        int count = 0;
        while(n >= 1) {
            n >>= 1;
            count++;
        }
        return count;
    }
public:
    int rangeBitwiseAnd(int m, int n) {
        int result = 0;
        while(m != 0 && n != 0 && log2(m) == log2(n)) {
            int tmp = pow(2, log2(m)-1);
            result += tmp;
            m -= tmp;
            n -= tmp;
        }
        return result;
    }
};