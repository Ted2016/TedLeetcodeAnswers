class Solution {
public:
    double myPow(double x, int n) {
        if(x < 0) {
            return myPow(-x, n)*(n%2 ? -1 : 1);
        }
        if(n < 0) {
            return 1/(myPow(x, -(n+1))*x);
        }
        if(n == 0 || x == 1) {
            return 1;
        } else if(n == 1) {
            return x;
        }
        return myPow(x*x, n/2)*(n%2 ? x : 1);
    }
};