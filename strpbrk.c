/*  strpbrk 
 *  返回一个指针，指向字符串2中的任意字符第一次出现在字符串1中的位置，
 *  如果没有相同的字符，则返回NULL
 */
 
 char *strpbrk(const char *strSrc, const char *str)
 {
    assert((strSrc != NULL) && (str != NULL));
    
    const char *s;
    while(*strSrc != '\0') {
        s = str;
        while(*s != '\0') {
            if(*strSrc == *s)           /*如果str中任意字符都不与当前strSrc字符相同，则strSrc移下一个*/
                return (char *)strSrc;
            ++s;
        }
        ++strSrc;
    }
    
    return NULL;
 }