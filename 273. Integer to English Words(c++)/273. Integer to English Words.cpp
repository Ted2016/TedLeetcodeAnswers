class Solution {
public:
    string numberToWords(int num) {
        if(num == 0) {
            return "Zero";
        } else if(num < 10) {
            return digits[num];
        } else if(num < 20) {
            return teens[num-10];
        } else if(num < 100) {
            return tens[num/10-2]+ ((num%10 == 0) ? "" : " " + numberToWords(num%10));
        } else if(num < 1000) {
            return digits[num/100] + " " + units[0] + ((num%100 == 0) ? "" : " " + numberToWords(num%100));
        } else if(num < 1000000) {
            return numberToWords(num/1000) + " " + units[1] + ((num%1000 == 0) ? "" : " " + numberToWords(num%1000));
        } else if(num < 1000000000) {
            return numberToWords(num/1000000) + " " + units[2] + ((num%1000000 == 0) ? "" : " " + numberToWords(num%1000000));
        } else {
            return numberToWords(num/1000000000) + " " + units[3] + ((num%1000000000 == 0) ? "" : " " + numberToWords(num%1000000000));
        }
    }
private:
    vector<string> digits {"", "One", "Two", "Three", "Four", "Five",
        "Six", "Seven", "Eight", "Nine"};
    vector<string> teens {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
        "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens {"Twenty", "Thirty", "Forty", "Fifty", "Sixty",
        "Seventy", "Eighty", "Ninety"};
    vector<string> units {"Hundred", "Thousand", "Million", "Billion"};
};