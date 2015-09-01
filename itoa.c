/* itoa 将整数转化为字符串
 * val: 待转化的整数。
 * radix: 是基数的意思,即先将val转化为radix进制的数，范围介于2-36，比如10表示10进制，16表示16进制。
 * buf: 保存转换后得到的字符串，和函数返回值相同
 */
 
char *itoa(int val, char *buf, unsigned int radix)
{
    char *bufptr;
    char *firstdig;
    char temp;
    unsigned int digval;
    
    assert(buf != NULL);
    
    bufptr = buf;
    if(val < 0) {
        *bufptr++ = '-';
        /*转化成正数*/
        val = (unsigned int)(-(int)val); 
    }
    
    /*存储数字转换成字符*/
    firstdig = bufptr;  /*指向字符串开头*/
    do {
        digval = (unsigned int)val % radix;
        val /= radix;
        if(digval > 9)
            *bufptr++ = (char)(digval - 10 + 'a');
        else
            *bufptr++ = (char)(digval + '0');
    } while(val > 0);
    
    /*设置字符串末尾，并将指针指向最后一个字符*/
    *bufptr-- = '\0'; 
    
    /*反转字符*/
    do {
        temp        = *bufptr;
        *bufptr     = *firstdig;
        *firstdig   = temp;
        
        --bufptr;
        ++firstdig;        
    }while(bufptr > firstdig);
    
    return buf;
}