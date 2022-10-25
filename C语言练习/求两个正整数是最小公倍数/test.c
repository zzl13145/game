#include <stdio.h>
int main() {
    int a, b, temp, i;
    printf("请输入两个数字，同空格隔开:");
    scanf_s("%d %d", &a, &b);
    // 保证 a >= b
    if (a < b) {
        temp = a;
        a = b;
        b = temp;
    }
    for (i = a; i > 0; i++)  // 从大数开始查找满足条件的数
        if (i % a == 0 && i % b == 0) {
            printf("%d 和 %d 的最小公倍数是%d", a, b, i);
            break;
        }

    return 0;
}
