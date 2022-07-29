#include <stdio.h>
int main()
{
	//冒泡排序
	int arr[] = { 1,55,4,7,98,456,13,65,475,125,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i, j;
	printf("排列前的数列是：\n");
	for (i = 0;i < sz;i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	for (i = 0;i < sz-1;i++)//n个数的数列总共扫描n-1次
	{
		for (j = 0;j < sz - 1 - i;j++)//每一趟扫描到arr[n-i-2]与arr[n-i-1]比较为止结束
		{
			if (arr[j] > arr[j + 1])//后一位数比前一位数小的话，就交换两个数的位置（升序)
			{
				int tmp = 0;
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}

	printf("排列好的数列是：\n");
	//输出排列好数列
	for (i = 0;i < sz;i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}
