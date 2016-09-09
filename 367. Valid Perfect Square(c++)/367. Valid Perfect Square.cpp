class Solution {
public:
    bool isPerfectSquare(int num) {
        long long large;
        int lhs = 1, rhs = 50000;
        while (lhs < rhs) {
            int mid = (rhs+lhs)>>1;
            large = mid*mid;
            if(large > num) {
                rhs = mid;
            } else if (large < num) {
                lhs = mid+1;
            } else {
                return true;
            }
        }
        return false;
       
    }
};