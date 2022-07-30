#include <stdio.h>
int main()
{
	int line = 0;
	scanf_s("%d", &line);
	int i = 0;
	//打印上半部分
	for (i=0;i <line;i++)
	{
		int j = 0;
		for (j = 0;j < line - 1 - i;j++)
			//打印空格
			printf(" ");
		for (j = 0;j < 2 * i + 1;j++)
			printf("*");
		printf("\n");
	}
	//打印下半部分
	for (i = 0;i <line-1;i++)
	{
		int j = 0;
		for (j = 0;j <= i;j++)//打印空格
			printf(" ");
		for (j = 0;j < 2 * (line - 1 - i) - 1;j++)//打印*
			printf("*");
		printf("\n");
	}
	return 0;
}