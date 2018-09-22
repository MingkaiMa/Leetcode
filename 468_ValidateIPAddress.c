
int isValidIP4(char* s){
    
    char* ptr = s;
    
    int n;
    int dotCnt = 0;
    
    
    while(*ptr != '\0'){
        n = atoi(ptr);
        if(n < 0 || n > 255)
            return 0;
        
        
//         printf("ptr is: %s\n", ptr);
        
//         printf("n is: %d\n", n);
        if(n == 0){
            if(*(ptr + 1) == '0')
                return 0;
            
            if(*ptr == '.')
                return 0;
        }
        
        else{
            if(*ptr == '0')
                return 0;
        }
        
        while(isdigit(*ptr))
            ++ptr;
        
        if(*ptr == '\0')
            break;
        
        if(isalpha(*ptr))
            return 0;
        
        if(*ptr == ':')
            return 0;
        
        
        if(*ptr == '.'){
            ++dotCnt;
            if(dotCnt <= 3 && *(ptr + 1) == '\0')
                return 0;
        }
        
        ++ptr;
        

        
        if(dotCnt > 3)
            return 0;   
    }
    
    if(dotCnt != 3)
        return 0;
    
    return 1;
}

int isValidIP6(char* s){
    char* ptr = s;
    
    int cnt = 0;
    int tempLen = 0;
    
    
    while(*ptr != '\0'){
        tempLen = 0;
        while(isalpha(*ptr) || isdigit(*ptr)){
            if(isalpha(*ptr)){
                if((*ptr >= 'a' && *ptr <= 'f') || (*ptr >= 'A' && *ptr <= 'F'))
                    ;
                else
                    return 0;
            }
            ++tempLen;
            ++ptr;
        }
        
        if(tempLen == 0)
            return 0;
        // printf("%s\n", ptr);
        
        if(tempLen == 1){
            int n = atoi(ptr - 1);
            if(n != 0)
                return 0;
        }
        
        // printf("1\n");

        // printf("tempLen: %d\n", tempLen);
        
        if(tempLen != 1 && tempLen > 4)
            return 0;
        
        // printf("2\n");
        
        if(*ptr == '\0')
            break;
        
        if(*ptr == '.')
            return 0;
        
        // printf("3\n");
        

        
        if(*ptr == ':'){
            ++cnt;
            if(cnt <= 7 && *(ptr + 1) == '\0')
                return 0;
        }
        
        ++ptr;
        
        if(cnt > 7)
            return 0;
    }
    


    if(cnt != 7)
        return 0;
    printf("cnt is: %d\n", cnt);
    return 1;
}


char* validIPAddress(char* IP) {
    
    if(isValidIP4(IP))
        return "IPv4";
    
    if(isValidIP6(IP) == 1)
        return "IPv6";
    
    
    return "Neither";
    
}
