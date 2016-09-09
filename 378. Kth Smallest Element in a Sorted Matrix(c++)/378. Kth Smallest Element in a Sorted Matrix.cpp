class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int size = matrix.size();
        int total_size = size*size;
        int lhs = matrix[0][0], rhs = matrix[size-1][size-1];
        while(lhs < rhs) {
            int mid = (lhs+rhs)>>1;
            int total = 0;
            for(const auto & item : matrix) {
                total += item.end() - upper_bound(item.begin(), item.end(), mid);
            }
            if (total <= total_size-k) {
                rhs = mid;
            } else {
                lhs = mid+1;
            }
        }
        return lhs;
    }
};