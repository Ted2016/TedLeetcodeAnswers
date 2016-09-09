char* convert(char* s, int numRows) {
    int len = strlen(s);
    char* ret = (char*)malloc(len+1);
    char* cur = ret;
    int step = 1;

    if(numRows > 1)
         step = (numRows-1)*2;

    for(int i = 0; i < len; i += step) {
        *cur++ = s[i];
    }
    if(numRows > 1) {
      for(int i = 1; i < numRows-1; i++) {
        int j = i;
        while(j < len) {
            *cur++ = s[j];
            j += step - i*2;
            if(j < len){
            *cur++ = s[j];
                j += i*2;
        }   
        }
    }   
    
    for(int i = numRows-1; i < len; i += step) {
        *cur++ = s[i];
    }   
    }
    *cur = '\0';
    return ret;
    
}

