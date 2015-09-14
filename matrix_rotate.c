/*编写一个函数，输入为一个矩阵，打印这个矩阵转置后的结果*/
#include<stdio.h>
#include<stdlib.h>

void 
transform(int *numbers, int rows, int  columns, int *tmps)
{
	if(rows <= 0 || columns <= 0 || numbers == NULL || *numbers == NULL)
		return ; 
		
	for(int i = 0 ; i < rows; i++)
		for(int j = 0 ; j < columns; j++)
			tmps[j * columns + (rows-1-i)] = numbers[i * rows + j];
	

	for(int k = 0 ;  k < columns; k++) {
		for(int l = 0; l < rows; l++)
			printf("%d ", tmps[k*rows + l]);
	}
}


int 
main()
{
	int a[4][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	int *nums = a[0];
	int size = sizeof(a)/sizeof(int);
	int *tmps = (int *)malloc(sizeof(int) *(size));;
	transform(nums,4, 4, tmps);
	return 0;
}