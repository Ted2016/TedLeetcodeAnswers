class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<string, char> map1;
        unordered_map<char, string> map2;
        vector<string> strs;
        split(str, " ", strs);
        if(strs.size() != pattern.size()) {
            return false;
        }
         for(int i = 0; i != strs.size(); i++) {
            if(map1.find(strs[i]) != map1.end() && map2.find(pattern[i]) != map2.end()) {
                if(map1[strs[i]] != pattern[i] || map2[pattern[i]] != strs[i]) {
                    return false;
                }
            } else if(map1.find(strs[i]) == map1.end() && map2.find(pattern[i]) == map2.end()){
                map1[strs[i]] = pattern[i];
                map2[pattern[i]] = strs[i];
            } else {
                return false;
            }
        }
        return true;
    }
    void split(string& s, string delim, vector<string>& ret)  {  
        size_t last = 0;  
        size_t index=s.find_first_of(delim,last);  
        while (index!=string::npos) {  
            ret.push_back(s.substr(last,index-last));  
            last=index+1;  
            index=s.find_first_of(delim,last);  
        }  
        if (index-last>0) {  
            ret.push_back(s.substr(last,index-last));  
        }  
    }  
};