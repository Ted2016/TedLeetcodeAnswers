class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) {
            return 0;
        }
        double guess = 1;
        double gap = x/guess-guess;
        while(gap > 0.00001 || gap < -0.00001){
            guess += gap/2;
            gap = x/guess-guess;
        }
        return guess;
    }
};