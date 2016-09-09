class Solution {
private:
    vector<int> getNext(string& needle) {
        int size = needle.size();
        vector<int> next(size, 0);
        int i = 2;
        while(i < size) {
            if(needle[0] != needle[i-1]) {
                next[i] = 0; 
                i++;
            } else {
                int j = 0;
                while(i < size && needle[j] == needle[i-1]) {
                    j++;
                    next[i] = j;
                    i++;
                } 
            }
        }
        return next;
    }
public:
    int strStr(string haystack, string needle) {

        int sizeA = haystack.size(), sizeB = needle.size();
        if(sizeA < sizeB) {
            return -1;
        } else if(sizeA == 0 && sizeB == 0) {
            return 0;
        }
        vector<int> next = getNext(needle);
        int i = 0, j = 0;
        while(i < sizeA) {
            while(i < sizeA && j < sizeB && haystack[i] == needle[j]) {
                i++;
                j++;
            }
            if(j == sizeB) {
                return i-j;
            } else if (i == sizeA) {
                return -1;
            }
            i = (j == 0 ? i+1 : i);
            j = next[j];
        }
        return -1;
    }
};