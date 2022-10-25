#include <stdio.h>
#include <string.h>
#include <assert.h>

void reverse(char* left, char* right)
{
	assert(left);//���ԣ��ж�arr�Ƿ�Ϊ��ָ�룩
	assert(right);//���ԣ��ж�arr�Ƿ�Ϊ��ָ�룩
	while (left < right)
	{
		char tmp = 0;
		tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}

void left_move(char* arr, int k)
{
	assert(arr);//���ԣ��ж�arr�Ƿ�Ϊ��ָ�룩
	int len = strlen(arr);
	reverse(arr, arr + k - 1);//����ǰ�벿�ݵ��ַ���       123 456 ->321 456
	reverse(arr + k, arr + len - 1);//�����벿�ݵ��ַ��� 321 456 ->321 654
	reverse(arr, arr + len - 1);//���������ַ���           321 654 ->456 123
}
int main()
{
	char arr[] = "abcdef";
	int k = 0;
	int sz = sizeof(arr) / sizeof(arr[0]) - 1;
	scanf_s("%d", &k);
	if (k >= sz)
	{
		k %= sz;
	}
	left_move(arr, k);
	printf("%s\n", arr);

	return 0;
}