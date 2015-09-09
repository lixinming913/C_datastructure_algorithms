/*最长公共子串*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100

char *
LCS(char *str1, char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char flag[N][N] = {0};
    
    char *p;       /*记录最长公共子串*/
    int start;      /*start表明最长公共子串的起始点*/
    int len  = 0;  /*len 表明最长公共子串长度*/
    int end = len;  /*end 表明最长公共子串的终止点*/
    
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
                end= j;
            }  
        }
    }
    
    start = end - len + 1;
    
    p = (char *)malloc(sizeof(char) * (len+1));
    for(i = start; i <= end; i++) {
        p[i-start] = str2[i];        
    }    
    p[len] = '\0';
    
    for(j = 0; j < len2;j++) {
        for(i = 0; i < len1; i++)
            printf("%2d", flag[i][j]);
            
        printf("\n");
    }
    
    return p;
}


int 
main()
{
    char str1[N], str2[N];
    
    printf("Please enter string1: ");
    gets(str1);
    printf("Please enter string2: ");
    gets(str2);
    
    printf("The max substr is: %s\n", LCS(str1, str2));
    
    return 0;
    
}