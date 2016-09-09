class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> table;
        while(n != 1) {
            table.insert(n);
            int num = 0;
            while(n != 0) {
                num += (n%10)*(n%10);
                n /= 10;
            }
            n = num;
            if(table.find(n) != table.end()) {
                return false;
            } 
        }
        return true;
    }
};