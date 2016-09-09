class Solution {
public:
    int hIndex(vector<int>& citations) {
        int size = citations.size(), i;
        for(i = size-1; i >= 0 && citations[i] >= size-i; i--) {
        }
        return size-i-1;
    }
};