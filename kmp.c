/*KMP算法*/

#include<stdio.h>

void getnext(string T, int *next)
{
    int i = 1;
    int j = 0;
    next[1] = 0;
    
    while(i < T[0]) {
        if(T[i] == T[j] || j == 0)
        {
            i++;
            j++;
            
            if(T[i] != T[j])
                next[i] = j;
            else
                next[i] = next[j];
        }
        else
            j = next[j];
    }
}

//返回子串T在主串S第pos个字符之后的位置
//若不存在，返回0
int index_kmp(string T, string S, int pos)
{
    int i = pos;
    int j = 1;
    int next[255];
    getnext(T, next);
    
    while(i <= S[0] && j <= T[0]) {
        if(0 == j || S[i] == T[j]) {
            i++;
            j++;
        }
        else {
            j = next[j];
        }        
    }
    
    if(j > T[0])
    {
        return i - T[0]; //全部匹配
    }
    else
        return 0;
    
}
