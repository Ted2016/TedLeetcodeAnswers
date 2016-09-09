class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n > 0) {
            int mod = 0;
        while(n != 1 && mod != 1) {
            mod = n%2;
            n /= 2;
        }
        if(mod != 1) {
            return true;
        }
    }
    return false;
    }
};