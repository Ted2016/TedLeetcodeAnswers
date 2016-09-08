class Solution {
public:
    int numTrees(int n) {
        vector<int> map (n+1, 0);
        map[0] = 1;
        map[1] = 1;
        for(int i = 2; i <= n; i++) {
            int total = 0;
            for(int j = 0; j < i; j++) {
                total += map[j]*map[i-j-1];
            } 
            map[i] = total;
        }
        return map[n];
    }
};