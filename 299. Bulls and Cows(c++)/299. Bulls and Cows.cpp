class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        unordered_map<char, int> mp;
        int size = secret.size();
        for(int i = 0; i < size; i++) {
            if(secret[i] == guess[i]) {
                bulls++;
            } 
            mp[secret[i]]++;
        }
        for(int i = 0; i < size; i++) {
            auto iter = mp.find(guess[i]);
            if(iter != mp.end()) {
                if(mp[guess[i]] == 0) {
                    mp.erase(iter);
                } else {
                    cows++;
                    mp[guess[i]]--;
                }
            }
        }
        cows -= bulls;
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};