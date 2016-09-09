class Solution {
public:
    bool isPowerOfFour(int num) {
        vector<int> map {1, 4, 16, 64, 256, 1024, 4096
        ,4096*4, 4096*16, 4096*64, 4096*256, 4096*1024, 4096*4096, 4096*4096*4, 4096*4096*16, 4096*4096*64 };
        if(find(map.begin(), map.end(), num) == map.end()) {
            return false;
        } else {
            return true;
        }
    }
};