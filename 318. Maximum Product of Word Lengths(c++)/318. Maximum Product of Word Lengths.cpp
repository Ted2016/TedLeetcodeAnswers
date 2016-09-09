class Solution {
public:
    int maxProduct(vector<string>& words) {
        sort(words.begin(), words.end(), [](string lhs, string rhs)
        { return lhs.size() < rhs.size();});
        int size = words.size();
        vector<int> bits{};
        for(const auto& item : words) {
            int bit = 0;
            for(const auto& chr : item) {
                bit |= (1<<(chr-'a'));
            }
            bits.push_back(bit);
        }
        int ret = 0;
        for(int i = 0; i < size; i++) {
            int tmp = 0;
            for(int j = size-1; j > i; j--) {
                if((bits[i] & bits[j]) == 0) {
                    tmp = words[i].size() * words[j].size();
                    break;
                }
            }
            ret = max(ret, tmp);
        }
        return ret;
    }
};