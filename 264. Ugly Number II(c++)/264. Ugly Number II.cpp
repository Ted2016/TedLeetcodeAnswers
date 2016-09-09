class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> n_2;
        vector<int> n_3;
        vector<int> n_5;
        vector<int> uglyNums{1};
        for(int i = 0; i < n-1; i++){
            int curr = uglyNums.back();
            n_2.push_back(curr*2);
            n_3.push_back(curr*3);
            n_5.push_back(curr*5);
            int min = n_2.front() > n_3.front() ? n_3.front() : n_2.front();
            min = min > n_5.front() ? n_5.front() : min;
            if(min == n_2.front()) {
                n_2.erase(n_2.begin());
            }
            if(min == n_3.front()) {
                n_3.erase(n_3.begin());
            }
            if(min == n_5.front()) {
                n_5.erase(n_5.begin());
            }
            uglyNums.push_back(min);
        }
        return uglyNums.back();
    }

};