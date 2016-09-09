class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) {
            return false;
        }
        unordered_map<char, char> map1;
        unordered_map<char, char> map2;
        int size = s.size();
        for(int i = 0; i < size; i++) {
            bool b1 = map1.find(s[i]) == map1.end(), b2 = map2.find(t[i]) == map2.end();
            if( b1 && b2) {
                map1[s[i]] = t[i];
                map2[t[i]] = s[i];
            } else if (!b1 && !b2 && map1[s[i]] == t[i] && map2[t[i]] == s[i]) {
                continue;
            } else {
                return false;
            }
        }
        return true;
        
    }
};