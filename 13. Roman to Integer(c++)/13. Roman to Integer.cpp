class Solution {
public:
    int romanToInt(string s) {
        vector<string> I = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        vector<string> X = {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string> C = {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        vector<string> M = {"M", "MM", "MMM"};
        vector<vector<string>> strs{I, X, C, M};
        int result = 0, num = 1000, pos = 0;
        for(auto item = strs.rbegin(); item != strs.rend(); item++) {
            for(auto str = (*item).rbegin(); str != (*item).rend(); str++) {
                if(s.find(*str) == pos) {
                    pos += (*str).size();
                    result += num*((*item).rend()-str);
                    break;
                }
            }
            num /= 10;
        }
        return result;
    }
};

