
int lengthOfLongestSubstring(char* s) {
    int lastSee[256];
    for(int i=0; i<=255;i++) lastSee[i]=-58;

    uint8_t begin=0,theLongest=0;

    for(int i=0; s[i]!= 0; i++){
        char temp = s[i];

        if(lastSee[temp]>=begin){
            begin=lastSee[temp]+1;
        }
    lastSee[temp]=i;
    uint8_t tempLong = i-begin+1;
    if(tempLong>theLongest) theLongest=tempLong;

    }
    return theLongest;
}
