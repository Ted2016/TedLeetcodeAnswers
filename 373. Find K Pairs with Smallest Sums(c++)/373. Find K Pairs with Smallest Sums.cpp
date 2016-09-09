class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        map<int, vector<pair<int, int>>> Map;
        for(int i : nums1) {
            for(int j : nums2) {
                Map[i+j].push_back(make_pair(i, j));
            }
        }
        vector<pair<int, int>> ret;
        for (auto iter = Map.begin(); iter != Map.end() && k > 0; iter++) {
            vector<pair<int, int>> vec = iter->second;
            for (auto v_iter = vec.begin(); v_iter != vec.end() && k > 0; v_iter++) {
                ret.push_back(*v_iter);
                k--;
            }
        }
        return ret;
    }
};