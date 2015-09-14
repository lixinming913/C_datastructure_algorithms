/*给定一个字符串，设计一个算法消除其中成对的括号，如果括号不成对，提示异常*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int delblag(char *s, char *tmp)
{
    if(s == NULL)
        return 1;    
    
    int flag = 0;
    int cnt = 0;
    while(*s != '\0'){
        if(flag < 0)
            break;
            
        if(*s == '(')
            flag += 1;
        else if(*s == ')')
            flag -= 1;
        else if(isdigit(*s)) {
            tmp[cnt++] = *s;
        }
        
        s++;        
    }
    tmp[cnt] = '\0';
    
    
    if(flag != 0 )
        return -1;
    else
        return 0;    
}
int main()
{
    char *s = "(1,(2,3),(4,(5,6),7))";
	char *tmp = (char*)malloc(sizeof(char)*strlen(s));
	int flag = delblag(s,tmp);

    if(flag == -1)
        printf("括号不成对");
    else if(flag == 0) 
        printf("成功消除后为：%s", tmp);
        
    else
        printf("没有元素哦");

    return 0;
}