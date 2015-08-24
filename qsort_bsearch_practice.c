#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int 
comp(const void *key1, const void *key2)
{
	return *(int *)key1- *(int*)key2;
}


int 
main()
{
	int a[] = {50,30,20,70,80,40,90,10,60};
    int k= 50;
	int *key = &k ;
    int *s
    
	qsort((void *)a, sizeof(a)/sizeof(a[0]), sizeof(a[0]),  comp);

	s = (int *)bsearch(key, a, sizeof(a)/sizeof(a[0]), sizeof(a[0]), comp);

	printf("%d", *(++s));

	return 0;
}