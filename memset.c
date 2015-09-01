/*memset 将s中前n个字节替换为c并返回s；*/

void *memset(void *str, int c, int count)
{
    assert(str != NULL);
    
    void *s = str;
    while(count--) {
        *(char *)s = (char)c;
        s = (char *)s + 1;
    }
    
    return str;
}