class Solution {
public:
    string intToRoman(int num) {
        vector<string> I = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        vector<string> X = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string> C = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        vector<string> M = {"", "M", "MM", "MMM"};
        return M[num/1000]+C[(num%1000)/100]+X[(num%100)/10]+I[num%10];
        
    }
};