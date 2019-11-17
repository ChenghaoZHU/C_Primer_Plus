#include <stdio.h>

void print_cube(double d);

int main(void)
{
    double d;
    printf("Enter a double float: ");
    scanf("%lf", &d);
    print_cube(d);

    return 0;
}

void print_cube(double d)
{
    printf("%lf's cube is %lf\n", d, d * d * d);
}