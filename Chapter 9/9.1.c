#include <stdio.h>
double min(double x, double y);

int main(void)
{
    double x, y;
    printf("Enter two double floats(q to quit): ");
    while (scanf("%lf %lf", &x, &y) == 2)
    {
        printf("%.4lf is the min value of %.4lf and %.4lf.\n", min(x, y), x, y);
        while (getchar() != '\n')
            continue;
        printf("Enter two double floats(q to quit): ");
    }
    printf("Bye.\n");
    return 0;
}

double min(double x, double y)
{
    return x < y ? x: y;
}