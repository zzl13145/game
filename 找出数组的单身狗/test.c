#include <stdio.h>
//找出单身狗
int main()
{
	int arr[] = { 1,2,3,4,5,1,2,3,4 };//找出这个数组中的唯一只有一个的元素，其他元素都是成对的
	int dog = 0;
	int i;
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (i = 0;i < sz;i++)
	{
		dog = dog ^ arr[i];//0异或一个数等于那个数本身(0^5=5),两个相同的数异或等于0（5^5=0）,故1^2^3^4^5^1^2^3^4=5
	}
	printf("%d\n", dog);

	return 0;
}