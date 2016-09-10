class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int length1 = nums1.size(), length2 = nums2.size();
        if(length2 < length1) {
        	return findMedianSortedArrays(nums2, nums1);
        }
        int lhs = 0, rhs = length1;
        while(lhs <= rhs) {
        	int mid = lhs + (rhs-lhs>>1), npos = (length1+length2+1>>1)-mid;
        	if(mid > 0 && npos < length2 && nums1[mid-1] > nums2[npos]) {
        		rhs = mid-1;
        	} else if(mid < length1 && npos > 0 && nums2[npos-1] > nums1[mid]) {
        		lhs = mid+1;
        	} else {
        		int left_max, right_min;
        		if(mid == 0) {
        			left_max = nums2[npos-1];
        		} else if (npos == 0) {
        			left_max = nums1[mid-1];
        		} else {
        			left_max = max(nums1[mid-1], nums2[npos-1]);
        		}
        		if((length1+length2)%2) {
        			return left_max;
        		}
        		if(mid == length1) {
        			right_min = nums2[npos];
        		} else if (npos == length2) {
        			right_min = nums1[mid];
        		} else {
        			right_min = min(nums1[mid], nums2[npos]);
        		}
        		return static_cast<double>(right_min+left_max)/2;
        	}
        }
        return 0;
    }
};