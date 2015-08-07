/**
 *  判断字符串中是否有对称括号
 *  ｛(,(,a,),)｝有对称括号，｛(,(,a｝不对称
 */


#include<stdio.h>
#include<stdlib.h>

bool
check(char *str)
{
    bool check = false;
    int i = 0;
    char *p = str;
    while(*p != '\0') {
        if(*p == '(') {
            check = true;
            ++i;
        } else if(*p == ')') {
            if(i == 0)
                return false;
                
            check = true;
            --i;
        }
                
        p++;
    }
    
    if(check && i == 0)
        return true;
    else
        return false;
}


int
main( )
{
    char s[] = {'(', '(', 'a', ')', ')'};
    
    if(check(s))
        printf("Blag exists !\n");
    else
        printf("Blag not exists !\n");
        
    return 0;
}