/*
 * 统计数组中逆序对个数
 */
 
 
#include<stdio.h>


int 
InversePairsCore(int* data, int* copy, int start, int end)
{
    if(start == end){
        copy[ start ] = data[ start ];
        return 0;
    }
    
    int length = (end - start) / 2;
    int left = InversePairsCore(data, copy, start, start+length);
    int right = InversePairsCore(data, copy, start+length+1, end);
    
    /*i 初始化为前半段最后一个数字的下标*/
    
    int i = start + length;
    
    /*j 初始化为后半段最后一个数字的下标*/
    
    int j = end;
    int indexcopy = end;
    int count = 0;
    
    while(i >= start && j >= start + length + 1){
        if(data[ i ] > data[ j ]){
            copy[ indexcopy-- ] = data[ i-- ];
            count += j - start - length;                  /*a[start+length+1...j...end为有序，
                                                                     *如果a[i]>a[j]>...a[start+length-1]
                                                                     */  
        } else {
            copy[ indexcopy-- ] = data[ j-- ];
        }
    }
    
    for(; i >= start; --i){
        copy[ indexcopy-- ] = data[ i ];
    }
    
    for(; j >= start + length + 1; --j){
        copy[ indexcopy-- ] = data[ j ];
    }
    
    return left + right +count;
}


int 
InversePairs(int *data, int length)
{
    if(data == NULL || length <= 0) {
        return 0;
    }
    
    int* copy = new int[ length ];
    for(int i = 0; i < length; ++i){
        copy[ i ] = data[ i ];
    }
    
    int count = InversePairsCore(data, copy, 0, length - 1);
    delete[ ] copy;
    
    return count;
}


int
main()
{
    int s[ ] = {7, 5, 6, 4};
    int number = InversePairs(s, 4);
    
    printf("逆序对个数为%d \n", number);
}