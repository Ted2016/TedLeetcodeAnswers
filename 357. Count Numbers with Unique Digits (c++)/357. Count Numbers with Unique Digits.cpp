class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int total = 1;
        int add = 9;
        for(int i = 1; i <= n; i++) {
            total += add;
            add = add*(10-i);
        }
        return total;
    }
};