// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
int guessNumber(int n) {
    int lhs = 1, rhs = n;
    int cur = ((n-1)>>2)+1;
    int comp = guess(cur);
    while(comp != 0) {
        if(comp == 1) {
            lhs = cur+1;
        } else {
            rhs = cur-1;
        }
        cur = lhs + ((rhs-lhs)>>2);
        comp = guess(cur);
    }
    return cur;
}
};