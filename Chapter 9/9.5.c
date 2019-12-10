#include <stdio.h>

void larger_of(double *, double *);

int main(void)
{
    double x, y;
    printf("Enter two double floats(q to quit): ");
    while (scanf("%lf %lf", &x, &y) == 2)
    {
        while (getchar() != '\n')
            continue;
        printf("Before x is %.2lf, y is %.2lf.\n", x, y);
        larger_of(&x, &y);
        printf("After x is %.2lf, y is %.2lf.\n", x, y);
        printf("Enter two double floats(q to quit): ");
    }
    
    return 0;
}

void larger_of(double * n, double * m)
{
    double larger = *n >= *m ? *n: *m;
    *n = *m = larger;
}