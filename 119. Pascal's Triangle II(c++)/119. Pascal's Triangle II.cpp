class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result{1};
        for(int i = 1; i < rowIndex; i++) {
            int tmp = result[0];
            for(int j = 1; j < result.size(); j++) {
                int n = result[j];
                result[j] = result[j]+tmp;
                tmp = n;
            }
            if(i%2) {
                result.push_back(tmp*2);
            }
        }
        int size = result.size();
        for(int i = (rowIndex%2 ? size-1 : size-2); i >= 0; i--) {
            result.push_back(result[i]);
        }
        return result;
    }
};