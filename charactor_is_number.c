/*
 * 表示了数值的字符串，实现一个函数用来判断字符串是否表示数值（包括整数和小数）
 */


#include<stdio.h>
#include<ctype.h>


bool IsExponential(char **str);

bool 
StrIsNum(char *str)
{
    if(str == NULL || *str == '\0')             /*空字符串*/
        return false;
    
    if(*str == '+' || *str == '-')                 /*第一个字符是'+'或者'-'说明后面应该是是正或者负数*/
        ++str;
    
    bool numeric = true;                           /*默认是真*/
    
    while(isdigit(*str) && *str != '\0')        /*字符串遍历到最后一个数字*/
        ++str;
    if(*str != '\0') {                                  /*数字后面还有字符的情况*/
        if(*str == '.') {                               /*如果是浮点数，遍历后面的每一个字符，如果后面都是数字就是浮点数*/
            ++str;
            while(isdigit(*str) && *str != '\0')
                ++str;
            if(*str == 'e' || *str == 'E')         /*浮点数后面还有科学计数法表示e时，看看后面符不符合科学计数法表示方式*/
                numeric = IsExponential(&str);            
        } else if (*str == 'e' || *str == 'E')  /*不是浮点数，是科学表示法时，再看看后面符不符合科学计数法表示方式*/
            numeric = IsExponential(&str);
        else
            numeric = false;                         /*以上情况皆不符合，肯定就不是数*/
    }
    
    return numeric && *str == '\0';        
}


/*用来匹配用科学计数法表示的数值的结尾部分 'e+10'*/
bool
IsExponential(char **str)
{
    if(**str != 'e' && **str != 'E')
        return false;
    
    ++(*str);
    if(**str == '+' || **str == '-')
        ++(*str);
    
    if(**str == '\0')
        return false;
        
    while(isdigit(**str) && (**str) != '\0')
        ++(*str);
    
    return (**str == '\0') ? true : false;
}


int
main()
{
    char *p = "1a.3.14";
    
    bool result = StrIsNum(p);
    if(!result)
        printf("It is not number.\n");
    else
        printf("It is number.\n");
        
    return 0;
}