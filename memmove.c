/*memmove memmove用于从src拷贝count个字符到dest，
 *如果目标区域和源区域有重叠的话，memmove能够保证源串在被覆盖之前将重叠区域的字节拷贝到目标区域中。
 *但复制后src内容会被更改。但是当目标区域与源区域没有重叠则和memcpy函数功能相同。
 */
 
void memmove(void *dest, const void *src, int count)
{
    assert(dest != NULL && src != NULL);
    
    void *address = dest;
    while(count--) {
        *(char *)dest = *(char *)src;
        dest = (char *)dest + 1;
        src  = (const char *)src + 1;
    }
    
    return address;
}