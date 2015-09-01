/*atoi把字符串转换成长整型数*/

int atoi(const char *str)
{
    int x = 0;
    const char *p = str;
    if(*str == '-' || *str == '+') {
        str++;
    }
    
    while(*str != 0) {
        if((*str > '9') || (*str < '0'))
            break;
        
        x = x*10 + (*str - '0');
        str++;
    }
    
    if(*p = '-')
        x = -x;
    
    return x;
}

