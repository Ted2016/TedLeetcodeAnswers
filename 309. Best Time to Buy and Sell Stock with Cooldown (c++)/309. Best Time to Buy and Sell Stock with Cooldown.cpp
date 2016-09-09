class Solution {
public:
    int maxProfit(vector<int>& prices) {
         
        int total = 0, size = prices.size();
        if(size == 0 || size == 1) {
            return total;
        }
        vector<int> sums (size+2, 0);
        int i = size-2;
        int count = 0;
        while(i >= 0) {
            bool isfirst = true;
            while(i >= 0 && prices[i] < prices[i+1]) {
                if(isfirst) {
                    if(count == 1) {
                        sums[i] = (prices[i+2]-prices[i] > 0 ? prices[i+2]-prices[i] : 0) +sums[i+2];
                        sums[i] = max(sums[i], max(sums[i+3]+prices[i+1]-prices[i], sums[i+2]));
                        
                    } else {
                        sums[i] = sums[i+3]+prices[i+1]-prices[i];
                    }
                    isfirst = false;
                    count = 0;
                } else {
                    sums[i] = sums[i+1]+prices[i+1]-prices[i];
                }
                i--;
            }
            if(i < 0) {
                break;
            }
            while(i >= 0 && prices[i] >= prices[i+1]) {
                sums[i] = sums[i+1];
                count++;
                i--;
            }
        }
        return sums[0];
    }
};


