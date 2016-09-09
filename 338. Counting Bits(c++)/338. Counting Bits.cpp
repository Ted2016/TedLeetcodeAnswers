class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret{0};
        int n = 1;
        for(int i = 0; i<num; i++) {
            int p = pow(2, n);
            if(i == p-1) {
                n++;
                p = pow(2,n);
            }
            ret.push_back(ret[i-p/2+1]+1);
        }
        return ret;
    }
};