class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        int i;
        for(i = 0; i != citations.size() && citations[i] >= i+1; i++) {
        }
        return i;
    }
};