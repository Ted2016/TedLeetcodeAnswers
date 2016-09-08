class Solution {
private:
    vector<string> recursive(const string& s, int loc, int num) const{
        vector<string> result;
        int restLength = s.length()-loc;
        if(restLength > num*3 || restLength < num ) {
            return result;
        } else if(num == 1) {
            string strNum = s.substr(loc, restLength);
            if(atoi(strNum.c_str()) <= 255 && isValid(strNum)) {
                result.push_back(strNum);
            }
            return result;
        }
        for(int i = 1; i <= 3; i++) {
            string strNum = s.substr(loc, i);
            if(atoi(strNum.c_str()) > 255 || !isValid(strNum)) {
                break;
            }
            auto tmp = recursive(s, loc+i, num-1);
            for(auto& str : tmp) {
                str = strNum+"."+str;
            }
            result.insert(result.end(), tmp.begin(), tmp.end());
        }
        return result;
    }

    bool isValid(const string& str) const{
        if(str.size() == 1) {
            return true;
        } else if(str[0] == '0') {
            return false;
        } else {
            return true;
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        return recursive(s, 0, 4);
    }
};