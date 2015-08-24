/*A,B 两个整数集合，设计一个算法求他们的交集，尽可能高效*/

#include<stdio.h>
#include<stdlib.h>
#define M 5
#define N 2


int 
cmp(const void *x, const void *y)
{
	int *div1 = (int *)x;
	int *div2 = (int *)y;

	return (*div1)-(*div2);
}


int 
main()
{
	int a[] = {-2, 1, 8, 6 ,2};
	int b[] = {2, 8};

	qsort(a, M, sizeof(int), cmp);
	qsort(b, N, sizeof(int), cmp);

	int res[M > N ? M : N];
	int k = 0;
	int i = 0;
	int j = 0;
	while(i < 5 && j < 2) {
		if(a[i] == b[j]) {
			res[k++] = a[i];
			i++;
			j++;
		}
		else if(a[i] < b[j])
			i++;
		else
			j++;
	}

	for(int i = 0; i < k; i++)
		printf("%d ", res[i]);

	return 0;
	
}