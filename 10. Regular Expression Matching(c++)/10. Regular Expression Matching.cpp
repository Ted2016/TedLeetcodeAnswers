class Solution {
public:
    bool isMatch_help(string s, string p) {
        string::size_type i = 0, j = 0;

        while (i < p.size() && j < s.size()) {
            if(i < p.size()-1 && p[i+1] == '*') {
                string s1(s.begin()+j, s.end());
                string p1(p.begin()+i, p.end());
                p1 = p1.front() + p1;
                string p2(p.begin()+i+2, p.end());
                if(isMatch_help(s1, p1) || isMatch_help(s1, p2)) {
                    return true;
                } else {
                    return false;
                }
            } else if(p[i] == '.' || p[i] == s[j]) {
                i++;
                j++;
            } else {
                return false;
            }        
        }
        
        if(s.size() == j) {
            string::size_type n = i;
            while(n < p.size()) {
                if(n < p.size()-1 && p[n+1] == '*') {
                    n += 2;
                } else {
                    return false;
                }
            }
            return true;
        } else {
            return false;
        }
    }
    
    string simplify(string s) {
    char c = '*';
    auto iter = s.begin();
    while(iter != s.end()) {
        if(iter < s.end()-1 && *(iter+1) == '*') {
            if(*iter == c) {
                iter = s.erase(iter, iter+2);
            } else {
                c = *iter;
                iter += 2;
            }
        } else {
            c = '*';
            iter++;
        }   
    }   
    return s;
   }
   
   bool isMatch(string s, string p) {
       p = simplify(p);
       return isMatch_help(s, p);
   }

};