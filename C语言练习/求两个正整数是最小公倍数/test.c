#include <stdio.h>
int main() {
    int a, b, temp, i;
    printf("�������������֣�ͬ�ո����:");
    scanf_s("%d %d", &a, &b);
    // ��֤ a >= b
    if (a < b) {
        temp = a;
        a = b;
        b = temp;
    }
    for (i = a; i > 0; i++)  // �Ӵ�����ʼ����������������
        if (i % a == 0 && i % b == 0) {
            printf("%d �� %d ����С��������%d", a, b, i);
            break;
        }

    return 0;
}
