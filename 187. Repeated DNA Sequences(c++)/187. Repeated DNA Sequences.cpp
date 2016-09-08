class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<int> ints(s.length());
        unordered_map<string, int> hash;
        vector<string> strs;
        int limit = s.length()-10;
        for(int i = 0; i <= limit; i++) {
            hash[string(s, i, 10)]++;
        }
        for(const auto& p : hash) {
            if(p.second >= 2) {
                 strs.push_back(p.first);
            }
        }
        return strs;
    }
};