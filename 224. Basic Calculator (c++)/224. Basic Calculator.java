class Solution {
     
public:
    int calculate(string s) {
    	stack<char> stk;
    	stk.push('+');
    	int result = 0;
    	for(int i = 0; i < s.length(); i++) {
    	    if(isspace(s[i])) {
    	        continue;
    	    } if(s[i] == '(') {
    			stk.push(stk.top());
    		} else if(s[i] == ')') {
    			stk.pop();
    		} else if(s[i] == '+' || s[i] == '-') {
    			if(stk.empty() || stk.top() == '+') {
    				stk.push(s[i]);
    			} else {
    				stk.push(s[i] == '+' ? '-' : '+');
    			}
    		} else {
    			int num = 0;
    			while(i < s.length() && isdigit(s[i]) ) {
    				num *= 10;
    				num += (s[i]-'0');
    				i++;
    			}
    			i--;
    			char c = stk.top();
    			stk.pop();
    			result = c == '+' ? result+num : result-num;
    		}
    	}
    	return result;

    }

};