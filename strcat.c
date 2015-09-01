/*strcat 实现两个字符串连接*/

char *strcat(char *strDes, const char *strSrc)
{
    assert((strDes != NULL) && (strSrc != NULL));
    
    char *address = strDes;
    while(*strDes != '\0')
        ++strDes;
        
    while((*strDes++ = *strSrc++) != '\0')
        ;
    
    return address;
}

char *strncat(char *strDes, const char *strSrc, int count)
{
    assert((strDes != NULL) && (strSrc != NULL));
    
    char *address = strDes;
    while(*strDes != '\0')
        ++strDes;
        
    while(count-- && *strSrc != '\0')
        *strDes++ = *strSrc++;
    *strDes = '\0';
    
    return address;
}