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
    
    while (*s2 != '\0' && *s2 == ' ')        
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


int #include <iostream>
#include <cstring>

using namespace std;

void remove_extra_space(char *str) 
{
    int Start = 0 , End = strlen(str);
    int NewStart = 0;
    while(Start < End)
    {
        //去掉开头的空格
        if(Start == 0)
        {
            while(Start < End && str[Start] == ' ')
            {        
                Start++;
            }
        }
        //处理中间的空格，多个空格值保存一个
        if(str[Start] == ' ')
        {
            str[NewStart++] = str[Start++];
            while(Start < End && str[Start] == ' ')
            {
                Start++;
            }
        }
        //复制非空格的字符
        else
        {
            str[NewStart++] = str[Start++];    
        }
    }
    //去掉末尾的空格
    if(str[NewStart-1] == ' ')
    {
        str[NewStart-1] = '\0';
    }
}

int main()
{
    char str[] = "  wo  shi Vincent  ";
    remove_extra_space(str);
    cout<<str<<endl;
    return 0;
}
main()
{
	char a[] = {' ', ' ', 'a', ' ', 'b', 'c', ' ', ' ', '\0'};
    
	tri(a);
    
	int i =0 ;
	while( a[i] != '\0')
		printf("%c",a[i++]);
}