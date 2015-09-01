/*memcpy将字符串2中的n个字符拷贝到字符串1中，并返回字符串2*/

void *memcpy(void *dest, const void *src, int count)
{
    assert((dest != NULL) && (src != NULL));
    
    void *address = dest;
    while(count--) {
        *(char *)dest = *(char *)src;
        dest = (char *)dest + 1;
        src  = (char *)src + 1;
    }
    
    return address;
}

/* 由src所指内存区域复制不多于count个字节到dest所指内存区域，如果遇到字符c则停止复制,
 * 返回值:如果c没有被复制，则返回NULL，否则，返回字符c 后面紧挨一个字符位置的指针。
 */

void *memccpy(void *dest, const void *src, int c, unsigned int count)
{
    assert((dest != NULL) && (src != NULL));
    while(count--) {
        *(char *)dest = *(char *)src;
        
        if(*(char *)src == (char)c) 
            return ((char *)dest + 1);
        
        dest = (char *)dest + 1;
        src  = (char *)src + 1;
    }
    
    return NULL;
}