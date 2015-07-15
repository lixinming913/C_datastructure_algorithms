/*
 *自行实现atoi函数，实现将字符串转换成整数
 */


#include<stdio.h>


/*
 *主要功能：字符串-》整数输出，"123"->123
 *测试用例：合法性，“”空字符串，“&*”非数字；区分正负“+”，“-”；边界值，整数溢出
 */
 
 
enum Status {kValid = 0 , kInvalid};
int g_nStatus = kValid;

int
m_atoi(const char *str)
{
    g_nStatus = kInvalid;
    long long num = 0;
    bool minus = false;

    if(str == NULL || *str == '\0') 
		return num;	
    else 
    {
        if(*str == '+')
            str++;
        else if(*str == '-')
        {
            minus = true;
            str++;
        }
        
        if(*str == '\0')
			return num;
            
        while(*str != '\0') {
            if(*str >= '0' && *str <= '9') {
                int flag = minus ? -1 : 1;
                num = num*10 + flag * (*str - '0');
                
                if((minus && num < (signed int)0x80000000) || (!minus && num > (0x7fffffff))) { /*边界判定*/
                    num = 0;
                    break;
                }
                
                str++;
            } else {
                num = 0;
                break;
            }
        }
        
        if(*str == '\0')
            g_nStatus = kValid;            
    
    }
    
    return num;
}

int 
main()
{
    const char *str1 = "*";
    int result1 = m_atoi(str1);
    if( result1 == 0 && g_nStatus == kInvalid){
            printf("Invalid input string\n");
    }
    else
        printf("%d\n", result1);
        
    return 0;    
}


