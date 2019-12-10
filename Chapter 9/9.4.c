#include <stdio.h>
double harmonicMean(double, double);

int main(void)
{
    double x, y;
    printf("Enter two double floats(q to quit): ");
    while (scanf("%lf %lf", &x, &y) == 2)
    {
        while (getchar() != '\n')
            continue;
        printf("The harmonic mean of %.2lf and %.2lf is %.4lf.\n", x, y, harmonicMean(x, y));
        printf("Enter two double floats(q to quit): ");
    }
    printf("Bye.\n");
    
    return 0;
}

double harmonicMean(double a, double b)
{
    return 2 * a * b / (a + b);
}