#include <stdio.h>

int main() {
    double e = 1.0, n = 1.0;
    int i = 1;
    while (1 / n > 1e-10) {
        e += 1 / n;
        i++;
        n = i * n;
    }
    printf("e=%f", e);
    return 0;
}
