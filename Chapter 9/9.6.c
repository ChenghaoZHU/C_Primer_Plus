#include <stdio.h>

void inplace_sort(double *, double *, double *);

int main(void)
{
    double x, y, z;
    printf("Enter three double floats(q to quit): ");
    while (scanf("%lf %lf %lf", &x, &y, &z) == 3)
    {
        while (getchar() != '\n')
            continue;
        printf("Before x is %.2f, y is %.2f, z is %.2f\n", x, y, z);
        inplace_sort(&x, &y, &z);
        printf("After x is %.2f, y is %.2f, z is %.2f\n", x, y, z);
        printf("Enter three double floats(q to quit): ");
    }
    
    return 0;
}

void inplace_sort(double * a, double * b, double * c)
{
    double temp;
    if (*a > *b) {
        temp = *a;
        *a = *b;
        *b = temp;
    }
    if (* b > *c)
    {
        temp = *b;
        *b = *c;
        *c = temp;
    }
    if (*a > *b) {
        temp = *a;
        *a = *b;
        *b = temp;
    }
}