class Solution {
public:
    int calculate(string s) {

        string level1 {'+', '-'};
        string level2 {'/', '*'};
        vector<string> strs;
        vector<char> chars;
        size_t begin = 0;
        auto pos = s.find_first_of(level1, begin);
        while(pos != string::npos) {
            strs.push_back(s.substr(begin, pos-begin));
            chars.push_back(s[pos]);
            begin = pos+1;
            pos = s.find_first_of(level1, begin);
        }
        strs.push_back(s.substr(begin, pos-begin));
        int total = 0;
        char c = '+';
        bool isfirst = true;
        for(int i = 0; i < strs.size(); i++) {
            if(isfirst){
                isfirst = false;
            } else {
                c = chars[i-1];
            }
            string str = strs[i];
            char cr;
            int tmp = 0;
            size_t b = 0;
            auto p = str.find_first_of(level2, b);
            if(p == string::npos) {
                tmp = atoi(str.c_str());
            } else {
                tmp = atoi(str.substr(b, p-b).c_str());
                while (p != string::npos) {
                    cr = str[p];
                    b = p+1;
                    p = str.find_first_of(level2, b);
                    int next = atoi(str.substr(b, p-b).c_str());
                    if(cr == '*') {
                        tmp *= next;
                    } else {
                        tmp /= next;
                    }
                }
            }
            if(c == '+') {
                total += tmp;
            } else {
                total -= tmp;
            }
        }
        return total;
    }
};