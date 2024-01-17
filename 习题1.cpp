#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//求[1，n]之间所有不能被3整除的整数之和，n的值由键盘输入。
//例如，如果输入12，则输出结果为：48

int main(void)
{
	int n;
	int sum = 0;
	int i = 1;
	printf("输入一个n值：\n");
	scanf("%d", &n);
	for (i; i <= n; i++)
	{
		sum = (i % 3 ? sum = sum + i : sum = sum);
	}
	printf("和为:%d", sum);

	return 0;
}