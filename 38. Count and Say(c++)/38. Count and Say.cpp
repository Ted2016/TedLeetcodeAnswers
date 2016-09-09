class Solution {
public:
    string countAndSay(int n) {
   
        string result = "1";
        for(int item = 1; item < n; item++) {
            string tmp;
            int size = result.size(), i = 0;
            while(i < size) {
                int count = 1;
                char cur = result[i];
                i++;
                while(i < size && result[i] == cur) {
                    count++;
                    i++;
                }
                tmp += to_string(count);
                tmp.push_back(cur);
            }
            result = tmp;
        }
        return result;
    }
};