class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> hash = vector<int>(26, 0);
        for(char c : s) {
        	hash[c-'a']++;
        }
        for(char c : t) {
        	hash[c-'a']--;
        	if(hash[c-'a'] < 0) {
        		return c;
        	}
        }
        return 0;
    }
};