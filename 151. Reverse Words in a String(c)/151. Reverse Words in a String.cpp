


void reverseString(char*, char*);

void reverseWords(char *s) {
    if(s == NULL||*s == '\0')
        return;
    char* left = s;
    char* right = s;
    while(*right == ' ') {   
        right++;
    }   
    *left++ = *right++;
    if(!(*(right-1))) {
        return;
    }   
    
    
    while(*right != '\0') {
        if(*right != ' ' || *(left-1) != ' ') {
            if(left != right) {
                *left = *right;
            }   
          left++;
        }   

        right++;
    }   
    if(*(left-1) == ' ') {
        *(--left) = '\0';
    } else {
        *(left) = '\0';
    }

   right = left-1;
   left = s;
   reverseString(left, right);

   char* space;
   while((space = strchr(left, ' ')) != NULL) {
       reverseString(left, space-1);
 left = space+1;
   }
   reverseString(left, right);

}

void reverseString(char* l, char* r) {
    char temp;
    while(l < r) {
        temp = *l;
        *l = *r;
        *r = temp;
        l++;
        r--;
    }
}