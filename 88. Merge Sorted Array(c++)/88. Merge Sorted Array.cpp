class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = m-1; i >= 0; i--) {
            nums1[i+n] = nums1[i];
        }
        int i = n, j = 0, k = 0, total = m+n;
        while(i < total && j < n) {
            if(nums1[i] < nums2[j]) {
                nums1[k] = nums1[i];
                i++;
            } else {
                nums1[k] = nums2[j];
                j++;
            }
            k++;
        }
        if(i == total) {
            while(j < n) {
                nums1[k] = nums2[j];
                j++;
                k++;
            }
        } else {
            while(i < total) {
                nums1[k] = nums1[i];
                i++;
                k++;
            }
        }
    }
};
};