#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

int jiecheng(int x)
{
	if (1 !=x )
	{
		return x * jiecheng(x - 1);
	}
	else
	{
		return 1;
	}
}
int main(void)
{
	int x = 0;
	for (x = 1; x <= 20; x++)
	{
		printf("%d\n", jiecheng(x));
	}
	return 0;
}