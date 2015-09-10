/*最长公共子串的长度*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100

int 
LCS_len(char *str1, char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char flag[N][N] = {0};
    
    int len  = 0;    /*len 表明最长公共子串长度*/   
    int i, j;
    
    for(i = 0; i < len1; i++) {
        for(j = 0; j < len2; j++) {
        
            if(str1[i] == str2[j]) 
                if(i == 0 || j == 0)
                    flag[i][j] = 1;
                else
                    flag[i][j] = flag[i-1][j-1] + 1;
                            
            if(flag[i][j] > len) {
                len = flag[i][j];
            }  
        }
    }
    
    return len;
}


int 
main()
{
    char str1[N] ;
    char str2[N] ;
    
    printf("Please enter string1: ");
    gets(str1);
    printf("Please enter string2: ");
    gets(str2);
    
    printf("The max substr is: %d\n", LCS_len(str1, str2));
    
    return 0;
    
}