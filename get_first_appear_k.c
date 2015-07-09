/*
 * 数字在排序数组中出现的次数
 * 比如3在{1,2,3,3,3,3,4,5}出现的次数
 */
 
 
 #include<stdio.h>
 
 
/* 确定数字k在数组中出现的首位置 */

int
GetFirstK(int numbers[ ], int length, int k, int start, int end)
{
    if(start > end)
        return -1;                                                                                               
    
    int mid = (start + end) / 2;
    int mid_data = numbers[mid ];
    
    if(mid_data == k) {
        if( (mid == 0) || (mid > 0 && numbers[mid + 1] != k) ) {                             
            return mid;
        } 
        else 
            end = mid - 1;
    } 
    else if( mid_data > k)                                                                                  
        end = mid - 1;
    else                                                                                                           
        start = mid + 1;    
        
    return GetFirstK(numbers, length, k, start, end);
}


/* 确定数字k在数组中出现的末位置 */

int
GetLastK(int numbers[ ], int length, int k, int start, int end)
{
    if(start > end)
        return -1;																						         
    
    int mid = (start + end) / 2;
    int mid_data = numbers[mid ];
    
    if(mid_data == k) {
        if( (mid == length - 1) || (mid < length - 1 && numbers[mid + 1] != k) ) {      
            return mid;
        } 
        else 
            start = mid + 1;
    } 
    else if( mid_data > k)                                                                                   
        end = mid - 1;
    else                                                                                                            
        start = mid + 1;    
        
    return GetFirstK(numbers, length, k, start, end);
}


/* 统计数字k在数组中出现的个数 */

int 
GetNumberK(int numbers[ ], int length, int k)
{
    int number_k = 0;
    
    if(length >0) {    
        int first = GetFirstK(numbers, length, k, 0, length - 1);
        int last = GetLastK(numbers, length, k, 0, length - 1);
      
	    if(first > -1 && last > -1)
			number_k = last - first + 1;
	}

    return number_k;
}


int 
main( )
{
    int data[ ] = {1, 2, 3, 3, 3, 3, 4, 5};
    int k = 3;
    int number_k;
    
    number_k = GetNumberK(data, 8, k);
    
    printf("%d appears %d times in array given.\n", k, number_k);
    
    return 0;
}

 