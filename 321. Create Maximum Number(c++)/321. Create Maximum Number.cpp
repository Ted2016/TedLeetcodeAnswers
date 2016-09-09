class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> ret(k, 0);
        for(int i = (n1 > k) ? k : n1; i >= 0 && k-i <= n2; i--) {
            vector<int> temp = numMerge(numPick(nums1, i), numPick(nums2, k-i));
            if(numCompare(ret, temp)) {
                ret = temp;
            }
        }
        return ret;
    }

    bool numCompare(const vector<int>& nums1,  const vector<int>& nums2) {
        for (auto iter1 = nums1.cbegin(), iter2 = nums2.cbegin(); iter1 < nums1.cend(); ) {
            if(*iter1 < *iter2) {
                return true; 
            } else if(*iter1 > *iter2) {
                return false;
            } else {
                iter1++;
                iter2++;
            }
        }
        return false;
    }
         

    vector<int> numPick(vector<int>& nums, int k) {
       vector<int> ret;
       auto iter1 = nums.cbegin();
       auto iter2 = nums.cend();
       while (k > 0 && iter2-iter1 > k) {
           iter1 = max_element(iter1, iter2-k+1)+1;
           ret.push_back(*(iter1-1));
           k--;
       }
        if (iter2- iter1 == k)
           ret.insert(ret.cend(), iter1, iter2);
       return ret;
    }

    vector<int> numMerge(const vector<int>& nums1, const vector<int>& nums2) {
        vector<int> ret;
        auto iter1 = nums1.cbegin();
        auto iter2 = nums2.cbegin();
        while (iter1 != nums1.cend() && iter2 != nums2.cend()) {
            if (*iter1 > *iter2 || (*iter1 == *iter2 && comp(iter1, nums1.cend(), iter2, nums2.cend()))) {
                ret.push_back(*iter1);
                iter1++;
            } else {
                ret.push_back(*iter2);
                iter2++;
            }
        }
        if (iter1 == nums1.cend()) {
            ret.insert(ret.cend(), iter2,  nums2.cend());
        } else {
            ret.insert(ret.cend(), iter1, nums1.cend());
        }
        return ret;
    }
    
     bool comp(vector<int>::const_iterator iter1, vector<int>::const_iterator iter_end1,
        vector<int>::const_iterator iter2, vector<int>::const_iterator iter_end2) {
        while (iter1 != iter_end1 && iter2 != iter_end2 && *iter1 == *iter2) {
            iter1++;
            iter2++;
        }
        if (iter1 == iter_end1) {
            return false;
        } else if(iter2 == iter_end2) {
            return true;
        } else if (*iter1 > *iter2) {
            return true;
        } else {
            return false;
        }

    }


 

};