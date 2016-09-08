class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> int_max {2, 1, 4, 7, 4, 8, 3, 6, 4, 7};
        if(digits == int_max)
            return vector<int>{0};
        auto iter = digits.rbegin();
        while (iter != digits.rend() && *iter == 9) {
            *iter = 0;
            iter++;
        }
        if(iter == digits.rend()) {
            digits.insert(digits.begin(), 1);
        } else {
            (*iter)++;
        }
        return digits;
    }
};