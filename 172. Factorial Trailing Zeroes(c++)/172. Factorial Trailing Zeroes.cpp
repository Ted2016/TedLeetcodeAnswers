class Solution {
public:
    int trailingZeroes(int n) {
        int total = 0;
        while(n >= 5) {
            n /= 5;
            total += n;
            
        }
        
        return total;
   
    }
};