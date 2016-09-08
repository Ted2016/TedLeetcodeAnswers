class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        for(const auto& str : strs) {
            string hashCode = str;
            sort(hashCode.begin(), hashCode.end());
            hash[hashCode].push_back(str);
        }
        vector<vector<string>> result;
        for(const auto& p : hash) {
            result.push_back(p.second);
        }
        return result;
    }
};