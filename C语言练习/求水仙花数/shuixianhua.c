#include <stdio.h>
//求水仙花数 方法一
int main() 
{
	int i = 0;
	for (i = 100;i < 1000;i++)
	{
		int sum = 0;
		int j = i;
		while (j)
		{
			int k = 0;
			k = j % 10;
			sum += k * k * k;
			j = j / 10;

		}
		if (sum == i)
		{
			printf("%d ", i);
		}

	}
	return 0;
}


//方法二

/*int main()
{
    int i = 0;
    int j = 0;
    int k = 0;
    printf("水仙花数：\n");
    for (i = 1; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            for (k = 0; k < 9; k++)
            {
                if (i * 100 + j * 10 + k == i * i * i + j * j * j + k * k * k)
                {
                    printf("%d\n", i * 100 + j * 10 + k);
                }
            }
        }
    }
    return 0;
}*/
