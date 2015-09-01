/*strcpy 字符串复制*/
char *strcpy(char *strDes, const char *strSrc)
{
    assert(strDes != NULL && strSrc != NULL);
    
    char *address = strDes;
    while((*strDes++ = *strSrc++) != '\0')
        ;
    
    return address;
}


char *strncpy(char *strDes, const char *strSrc, int count)
{
    assert(strDes != NULL && strSrc != NULL);
    
    char *address = strDes;
    while(count-- && *strSrc != '\0')
        *strDes++ = *strSrc++;
    *strDes = '\0';
    
    return address;
}