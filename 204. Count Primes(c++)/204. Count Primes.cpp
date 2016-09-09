class Solution {
public:
    int countPrimes(int n) {
        if(n == 0 || n == 1) {
            return 0;
        }
        vector<bool> bools(n, true);
        bools[0] = false;
        bools[1] = false;
        
        for(int begin = 2; begin*begin < n; begin++) {
            if(!bools[begin]) continue;
            for(int i = begin*begin; i < n; i += begin) {
                bools[i] = false;
            }
        }
        int count = 0;
        for(bool c : bools) {
            if(c) {
                count++;
            }
        }
        return count;
    }
};