#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//斐波那契数列的递归和递归写法
int rabbit_digui(int n)
{
	if (n>2)
	{
		return rabbit_digui(n - 1) + rabbit_digui(n - 2);
	}
	else
	{
		return 1;
	}
}
int rabbit_cycle(int n)
{
	int a = 1;
	int b = 1;
	int num = 0;
	if (n > 2)
	{
		for (; n - 2 > 0; n--)
		{
			num = a + b;
			a = b;
			b = num;
		}
		return num;
	}
	else
	{
		return 1;
	}
}
int main(void)
{
	int n = 0;
	scanf("%d", &n);
	printf("%d\n", rabbit_digui(n));
	printf("%d", rabbit_cycle(n));

	return 0;
}