/*测试字符串1是否为字符串2的移位后得到*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

bool test(char *str1, char *str2)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);

	if(len1 != len2 || len1 == 0 || len2 == 0)
		return false;

	char *buffer = (char *)malloc(sizeof(len1+len2+1));
	strcpy(buffer, str1);
	strcat(buffer, str1);
	if(strstr(buffer, str2)==NULL)
		return false;
	else
		return true;
}

void main()
{
	char *s1 = "ABCD";
	char *s2 ="BCDA";
	if(test(s1,s2))
		printf("yes\n");
	else
		printf("no\n");
}