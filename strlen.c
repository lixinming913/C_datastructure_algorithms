/*strlen 字符串长度*/

int strlen(const char *str)
{
    assert(str != NULL);
    
    int len = 0;
    while(*str++ != '\0')
        ++len;
        
    return len;
}