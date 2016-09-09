class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        auto end1 = unique(nums1.begin(), nums1.end());
        auto end2 = unique(nums2.begin(), nums2.end());
        vector<int> ret;
        auto iter1 = nums1.begin(), iter2 = nums2.begin();
        while(iter1 != end1 && iter2 != end2) {
            if (*iter1 == *iter2) {
                ret.push_back(*iter1);
                iter1++;
                iter2++;
            } else if(*iter1 < *iter2) {
                iter1++;
            } else {
                iter2++;
            }
        }
        return ret;
    }
};