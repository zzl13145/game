#include <stdio.h>
#include <string.h>
#include <assert.h>

void reverse(char* left, char* right)
{
	assert(left);//¶ÏÑÔ£¨ÅĞ¶ÏarrÊÇ·ñÎª¿ÕÖ¸Õë£©
	assert(right);//¶ÏÑÔ£¨ÅĞ¶ÏarrÊÇ·ñÎª¿ÕÖ¸Õë£©
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
	assert(arr);//¶ÏÑÔ£¨ÅĞ¶ÏarrÊÇ·ñÎª¿ÕÖ¸Õë£©
	int len = strlen(arr);
	reverse(arr, arr + k - 1);//ÄæĞò×ó±ß×Ö·û´®
	reverse(arr + k, arr + len - 1);//ÄæĞòÓÒ±ß×Ö·û´®
	reverse(arr, arr + len - 1);//ÄæĞòÕû¸ö×Ö·û´®
}
int main()
{
	char arr[] = "abcdef";
	int k = 0;
	scanf_s("%d", &k);
	left_move(arr, k);
	printf("%s\n", arr);

	return 0;
}