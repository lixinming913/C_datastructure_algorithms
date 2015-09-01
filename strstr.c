/* strstr
 * 返回一个指针，它指向字符串2第一次出现在字符串1中的位置
 * 如果不含有，则返回NULL
 */
 
char *strstr(const char *strSrc, const char *str)
{
    assert((strSrc != NULL) && (str != NULL));
    
    const char *s = strSrc;
    const char *t = str;
    for(; *t != '\0'; ++strSrc) { /*记录每次strSrc开始匹配的位置*/
        for(s = strSrc, t = str; *t != '\0' && *s == *t; ++s,++t)
            ;
        if(*t = '\0')
            return (char *)strSrc;
    }
    
    return NULL;
}