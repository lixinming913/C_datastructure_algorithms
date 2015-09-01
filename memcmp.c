/* memcmp 比较内存区域buf1和buf2的前count个字节
 * 当buf1<buf2时，返回值<0,当buf1=buf2时，返回值=0, 当buf1>buf2时，返回值>0
 */
 
int memcmp(const void *s, const void *t, int count)
{
    assert((s != NULL) && (t != NULL));
    
    while(*(char *)s && *(char *)t && *(char *)s == *(char *)t && count--) {
        s = (char *)s + 1;
        t = (char *)t + 1;
    }
    
    return (*(char *)s - *(char *)t);
}