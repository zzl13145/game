#include <stdio.h>
//回调函数求阶乘（不考虑栈溢出）
int fun1(int n)
{
	if (n == 1 || n == 0)
		return 1;//0的阶乘等于1
	else
		return n * fun1(n - 1);
}

int main()
{
	int n = 0;
	scanf_s("%d", &n);
	int sum = fun1(n);
	printf("sum = %d", sum);
	return 0;
}