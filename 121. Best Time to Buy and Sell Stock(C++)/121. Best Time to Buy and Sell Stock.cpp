class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty() || prices.size() == 1) {
            return 0;
        }
        int max_n = 0;
        int tmp = 0, prev = prices.front();
        for(auto i = prices.begin()+1; i != prices.end(); i++) {
            tmp += *i-prev;
            max_n = max(max_n, tmp);
            prev = *i;
            if(tmp < 0) {
                tmp = 0;
            }
        }
        return max_n;
    }
};