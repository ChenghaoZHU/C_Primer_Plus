#include <stdio.h>

void to_base_n(int, int);

int main(void)
{
    int n, base;
    printf("Enter an integer and a base(from 2 to 10): ");
    while (scanf("%d %d", &n, &base) == 2)
    {
        while (getchar() != '\n')
            continue;
        if (base < 2 || base > 10) {
            printf("Enter an integer and a base(from 2 to 10): ");
            continue;
        }
        printf("%d in base %d is ", n, base);
        to_base_n(n, base);
        printf("\n");
        printf("Enter an integer and a base(from 2 to 10): ");
    }
    printf("Done.\n");
    return 0;
}

void to_base_n(int n, int base)
{
    if (n == 0)
        return;
    to_base_n(n / base, base);
    printf("%d", n % base);
}
