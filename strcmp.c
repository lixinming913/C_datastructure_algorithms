/*strcmp 字符串比较*/

int strcmp(const char *s, const char *t)
{
    assert(s != NULL && t != NULL);
    
    while(*s && *t && *s == *t) {
        ++s;
        ++t;
    }
    
    return (*s - *t);
}

int strncmp(const char *s, const char *t, int count)
{
    assert(s != NULL && t != NULL);
    
    while(*s && *t && *s == *t && count--) {
        ++s;
        ++t;
    }
    
    return (*s - *t);
}