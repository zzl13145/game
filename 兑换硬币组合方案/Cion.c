#include <stdio.h>
int main()
{
    int i = 0;
    int j = 0;
    int k = 0;
    int count = 0;
    for (i = 1; i < 20; i++)
    {
        for (j = 1; j < 50; j++)
        {
            for (k = 1; k < 100; k++)
            {
                if ((100 == i * 5 + j * 2 + k) && (50 == i + j + k))
                {
                    printf("5分的%-2d个，2分的%-2d个，1分的%-2d个\n", i, j, k);
                    count++;
                }
            }
        }
    }
    printf("一共有 %d 种情况,如上表。\n",count);
    return 0;
}
