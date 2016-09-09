class Solution {
public:
    bool isPalindrome (int x) {
        if(x < 0)
            return false;
        int n = 0, temp = x;
        while(temp != 0) {
            temp /= 10; 
            n++;
        }
        for(int i = 0; i < n/2; i++) {
            int m = pow(10, n-2*i-1);
            if(x%10 != x/m) {
                return false;
            }
            x = x%m/10;
        }
        return true;
    }   
};