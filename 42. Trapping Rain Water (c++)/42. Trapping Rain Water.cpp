class Solution {
public:
    int trap(vector<int>& height) {
        int lhs = 0, rhs = height.size()-1;
        int sum = 0;
        int lheight = 0, rheight = 0;
        while(lhs < rhs) {
            rheight = max(rheight, height[rhs]);
            lheight = max(lheight, height[lhs]);
            if(rheight > lheight) {
                if(height[lhs] < lheight) {
                    sum += lheight-height[lhs];
                } 
                lhs++;
                
            } else {
                if(height[rhs] < rheight) {
                    sum += rheight-height[rhs];
                }
                rhs--;
            }
        }
        return sum;
    }
};