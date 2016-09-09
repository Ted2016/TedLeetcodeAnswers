class Solution {
    public :
    int reverse(int x) {
        vector<int> table;
        while(x != 0) {
            table.push_back(x%10);
            x /= 10;
        }
        for(auto iter = table.begin(); iter != table.end(); iter++) {
            if(x > INT_MAX/10 || x < INT_MIN/10) {
                return 0;
            }
            x = 10*x + (*iter);
        }
        return x;
    }
};