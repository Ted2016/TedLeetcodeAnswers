class Solution {
public:
    int myAtoi(string str) {
        int ret = 0;
        bool is_neg = false;
        int i = 0;
        while(i != str.size() && isspace(str[i])) {
            i++;
        }
        int n = i;
        for(; i != str.size(); i++) {
            if(i == n && str[i] == '-') {
                is_neg = true;
                continue;
            }
            if(i == n && str[i] == '+') {
                continue;
            }
            if(!isdigit(str[i])) {
                break;
            }
            if(ret > INT_MAX/10 || (ret == INT_MAX/10 && str[i] > '7')) {
                ret = INT_MAX;
                break;
            }
            if(ret < INT_MIN/10 || (ret == INT_MIN/10 && str[i] > '8')) {
                ret = INT_MIN;
                break;
            }
            if (is_neg == true)
                ret = ret*10 + -1*(str[i] - '0');
            else
                ret = ret*10 + str[i] - '0';
            
        }
        return ret;
    }
};