#include <stdio.h>
//�ص�������׳ˣ�������ջ�����
int fun1(int n)
{
	if (n == 1 || n == 0)
		return 1;//0�Ľ׳˵���1
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