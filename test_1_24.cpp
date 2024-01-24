#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

void point_run(int nian)
{
	if ((0 == nian % 4) && (0 != nian % 100))
	{
		printf("%d是闰年", nian);
	}
	else
	{
		printf("%d不是闰年", nian);
	}
}

int main(void)
{
	int a = 0;
	scanf("%d",&a);
	point_run(a);

	return 0;
}