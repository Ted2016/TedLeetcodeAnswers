class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 0)
            return false;
        double i = n;
        while (i != 1.0 && floor(i) == i) {
            i = i/3;
        }
        if (i == 1.0)
            return true;
        else
            return false;
    }
};