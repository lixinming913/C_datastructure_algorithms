/*memchr 从buf所指内存区域的前count个字节查找字符c
 *当第一次遇到字符ch时停止查找。如果成功，返回指向字符ch的指针;否则返回NULL
 */
void *memchr(const void *buf, int c, int count)
{
   assert(buf != NULL);

   while(count--) {
        if(*(char *)buf == (char)c)
            return (void *)buf;
        
        buf = (char *)buf + 1;
   }
   return NULL;
}