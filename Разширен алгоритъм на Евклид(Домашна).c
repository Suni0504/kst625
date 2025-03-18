#include <stdio.h>

int extended_gcd(int a, int b, int *x, int *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    
    int x1, y1;
    int gcd = extended_gcd(b % a, a, &x1, &y1);

    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

int main() {
    int a, b, x, y;
    
    printf("Въведете две числа: ");
    if (scanf("%d %d", &a, &b) != 2) {
        printf("Грешка: Моля, въведете валидни цели числа.\n");
        return 1;
    }

    int gcd = extended_gcd(a, b, &x, &y);

    printf("НОД(%d, %d) = %d\n", a, b, gcd);
    printf("Коефициенти x = %d, y = %d\n", x, y);

    return 0;
}