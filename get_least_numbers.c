/*
 *最小的k个数
 */


#include<stdio.h>
#include<stdlib.h>
#define false 0
#define true 1


int
less(int x, int y)
{
    return x<=y;
}


void
exchange(int a[ ], int i, int j)
{
    int temp;
    
    temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}


int 
partition(int  a[ ], int lo, int hi)
{
    int i=lo,j=hi+1;

    while(1) {
        while( less(a[ ++i ], a[ lo ]) ) {
            if(i == hi) 
                break;
        }
        
        while( less(a[ lo ], a[ --j ]) ) {
            if(j == lo)
                break;
        }
        
        if(i >= j)
            break;
            
        exchange(a, i, j);
    }
    
    exchange(a, lo, j);
    
    return j;
}


void 
GetLeastNumbers(int input[ ], int n, int *output, int k)
{
    if( input == NULL || output == NULL 
        || k > n || n <= 0 || k <= 0)
    {
        return;
    }
    
    int start = 0;
    int end = n - 1;
    int index = partition(input, start, end);
    
    while(index != k-1) {
        if(index > k-1) {
            end = index - 1;
            index = partition(input, start, end);
        } else {
            start = index +1;
            index = partition(input, start, end);
        }
    }

    for(int i =0 ; i < k; ++i)
        output[ i ] = input[ i ];
}


void 
main( )
{
    int in[ ] = {1, 5, 4, 6, 2, 7, 3, 8};
    int k =4;
    int length = 8;
    int *out = new int[k];
    
    GetLeastNumbers( in, length, out, k);
    
    for(int i = 0; i < k; i++)
        printf("%d ",out[i]);
}