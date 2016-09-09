class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        int zero_num = 0;
        for(auto num : nums) {
            string str = to_string(num); 
            if(str != "0") {
               strs.push_back(str);
            } else {
                zero_num++;
            }
        }
        string ret = "";
        if(strs.empty()) {
           return "0";
        }
        sort(strs.begin(), strs.end(), str_compare);
        for_each(strs.begin(), strs.end(), [&ret](const string& str) {
            ret += str;
        });
        string zeros(zero_num, '0');
        return ret+zeros;
    }
    
    static bool str_compare (const string& lhs, const string& rhs) {
        string s1 = lhs+rhs;
        string s2 = rhs+lhs;
        return s1 > s2;
    }
};