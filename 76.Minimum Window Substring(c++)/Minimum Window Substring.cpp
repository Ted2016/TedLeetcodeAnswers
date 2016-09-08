class Solution {
public:
    string minWindow(string s, string t) {
        int lhs = 0, rhs = 0, count = 0, min_length = INT_MAX, pos = 0;
        unordered_map<char, int> bench_mark;
        for(char c : t) {
        	bench_mark[c]++;
        }
        unordered_map<char, int> hash;
        while(rhs < s.size()) {
        	if(count < t.size()) {
        		if(t.find(s[rhs]) != string::npos) {
        			if(hash[s[rhs]] < bench_mark[s[rhs]]) {
        				count++;
        			}
        			hash[s[rhs]]++;
        		} 
        		rhs++;
        	} 
        	 while(count == t.size()) {
        	if(t.find(s[lhs]) != string::npos ) {
    			if(hash[s[lhs]] == bench_mark[s[lhs]]) {
        			count--;
        			pos = min_length > rhs-lhs ? lhs : pos ;
        			min_length = min(min_length, rhs-lhs);
        		}
        		hash[s[lhs]]--;
    		} 
    		lhs++;
        }
    }
       
        return min_length == INT_MAX ? "" : s.substr(pos, min_length);
    }
};