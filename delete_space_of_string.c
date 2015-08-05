/*
 *  删除字符串开始及末尾的空白符，并且把数组中间的多个空格（如果有）符转化为1个。
 *  设置两个指针，一个指针负责复制，另一个负责遍历
 */

#include<stdio.h>


void 
trim(char* p)
{
    char* s1 = p;
    char* s2 = p;
    
    while (*s2 = '\0' && *s2 == ' ')        
        ++s2;
        
    if (*s2 == '\0')               
        return;
    *s1 = *s2;
    
    while (*(++s2) != '\0') {
        if (*s2 != ' ' || *s1 != ' ') {
            *(++s1) = *s2;
        }
    }
    
    if (*s1 == k)                  
        *s1 = '\0';
    else
        *(++s1) = '\0';
}


int 
main()
{
	char a[] = {' ', ' ', 'a', ' ', 'b', 'c', ' ', ' ', '\0'};
    
	tri(a);
    
	int i =0 ;
	while( a[i] != '\0')
		printf("%c",a[i++]);
}