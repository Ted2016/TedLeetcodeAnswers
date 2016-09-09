class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        int profit = 0;
        auto iter = prices.cbegin();
        while(iter != prices.cend()-1) {
            while(iter != prices.cend()-1 && *(iter+1) <= *iter) {
                iter++;
            }
            int buy = 0;
            if(iter == prices.cend()-1){
                break;
            } else {
                buy = *iter;
            }
            
            while(iter != prices.cend()-1 && *(iter+1) >= *iter) {
                iter++;
            }
            int sell = *iter;
            profit += (sell-buy);
            
        }
        return profit;
    }
};