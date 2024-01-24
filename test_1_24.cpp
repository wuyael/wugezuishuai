#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

void halfsearch(int arr[], int k)
{
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]-1);
	while (left <= right)
	{
		int mid = (left + right) / 2;
			if (arr[mid] < k)
			{
				left = mid + 1;
			}
			else if (arr[mid] > k)
			{
				right = mid - 1;
			}
			else
			{
				printf("找到了，下标是%d\n", mid);
				break;
			}
	}
	if (right < left)
	{
		printf("输入错误，未找到\n");
	}
}

int main(void)
{
	int arr[] = { 2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
	int k = 0;
	scanf("%d", &k);
	halfsearch(arr, k);

	return 0;
}