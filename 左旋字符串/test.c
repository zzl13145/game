#include <stdio.h>
#include <string.h>
#include <assert.h>

void reverse(char* left, char* right)
{
	assert(left);//断言（判断arr是否为空指针）
	assert(right);//断言（判断arr是否为空指针）
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
	assert(arr);//断言（判断arr是否为空指针）
	int len = strlen(arr);
	reverse(arr, arr + k - 1);//逆序前半部份的字符串       123 456 ->321 456
	reverse(arr + k, arr + len - 1);//逆序后半部份的字符串 321 456 ->321 654
	reverse(arr, arr + len - 1);//逆序整个字符串           321 654 ->456 123
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