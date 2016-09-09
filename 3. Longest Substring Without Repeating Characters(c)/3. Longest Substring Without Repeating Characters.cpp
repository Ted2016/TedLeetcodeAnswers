int lengthOfLongestSubstring(char* s) {
    if(*s == 0)
        return 0;
    int longest = 1; 
    char* cur = s + 1;
    char* start = s;
    char* end = s;
    while(*cur != '\0') {
        int curlen = 1;
        for(int i = 0; start+i != end + 1; i++) {
            if(*(start+i) == *cur){
                start = start + i + 1;
                break;
            }   
        }
        end = cur;
        cur++;
        curlen = end - start + 1;
        if(curlen > longest)
            longest = curlen;
    }   
    return longest;
}