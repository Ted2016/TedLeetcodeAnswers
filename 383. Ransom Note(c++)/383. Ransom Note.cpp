class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        array<int, 26> table{0};
        int total = 0;
        for(auto c : ransomNote) {
            table[c-'a']++;
            total++;
        }
        for(auto c : magazine) {
            if(total == 0) {
                break;
            }
            if(table[c-'a'] != 0) {
                total--;
                table[c-'a']--;
            }
        }
        return total == 0;
    }
};




