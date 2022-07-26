#include <stdio.h>
int main() 
{
	int i = 0;
	for (i = 100;i < 100000;i++)
	{
		int sum = 0;
		int j = i;
		if (i < 1000)
		{
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
		else if(i>=1000 && i<10000)
		{
			while (j)
			{
				int k = 0;
				k = j % 10;
				sum += k * k * k * k;
				j = j / 10;

			}
			if (sum == i)
			{
				printf("%d ", i);
			}
		}
		else if (i >= 10000 && i < 100000)
		{
			while (j)
			{
				int k = 0;
				k = j % 10;
				sum += k * k * k * k * k;
				j = j / 10;

			}
			if (sum == i)
			{
				printf("%d ", i);
			}
		}
	}
	return 0;
}