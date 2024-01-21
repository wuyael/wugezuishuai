#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//输入多个整数，并对其进行从大到小的排序,最后打印；
int main(void)
{
	int n = 0;
	int num[10];
	int i = 0;
	int j = 1;
	int k = 1;
	int Max = 0;
	printf("输入十个数字：");
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &num[i]);
	}

	for (j = 0; j < 9; j++)
	{
		i = j;
		for (i = 0; i < 9; i++)
		{
			int da = num[i];
			int xiao = num[i + 1];//对原来两个数值保存
			if (num[i] < num[i + 1])//对比两数字，把大的放左边
			{
				num[i] = xiao;
				num[i + 1] = da;
			}
		}
	}
	for (k = 0; k < 10; k++)
	{
		printf("%d ", num[k]);
	}

	return 0;
}
