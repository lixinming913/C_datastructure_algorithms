/*strcspn 返回字符串1中不包含字符串2中的字符的前缀的长度
 *若strcspn()返回的数值为n，则代表字符串s1开头连续有n个字符都不含字符串s2内的字符。
 */

 
int strcspn(const char *strSrc, const char *str)
{
    assert((strSrc != NULL) && (str != NULL));
    
    const char *s;
    const char *t = strSrc;
    while(*t != '\0') {
        s = str;
        while(*s != '\0') {
            if(*t == *s)
                return t - strSrc;
            ++s;
        } 
        ++t;;
    }
    
    return 0;
}

/*strspn返回字符串中第一个不在指定字符串中出现的字符下标*/
/*返回字符串s1开头连续包含字符串s2的字符数目*/
int strspn(const char *strSrc, const char *str)
{
   assert((strSrc != NULL) && (str != NULL));

   const char *s;
   const char *t = strSrc;
   while(*t != '\0') {
        s = str;
        while(*s != '\0') {
           if(*t == *s) 
               break;
           ++s;
        }
        
        if(*s == '\0')
            return t - strSrc;
        ++t;
   }
    
   return 0;
}