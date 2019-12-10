#include <stdio.h>
#include <stdlib.h>
double power_d(double, int);

int main(void)
{
    double x;
    int n;
    printf("Enter a number and its power(q to quit): \n");
    while (scanf("%lf %d", &x, &n) == 2)
    {
        while (getchar() != '\n')
            continue;
        printf("%.2lf to the power of %d is %.2lf.\n", x, n, power_d(x, n));
        printf("Enter a number and its power(q to quit): \n");
    }
    printf("Bye.\n");
    
    return 0;
}

double power_d(double x, int n)
{
    double res;
    int i;
    if (x == 0)
    {
        if (n == 0)
        {
            printf("0 to the power of 0 is undefined, here it is deemed 1.\n");
            res = 1;
        } else
        {
            res = 0;
        }
    } 
    else if (n == 0)
    {
        res = 1;
    }
    else
    {
        res = 1.0;
        for (i = 0; i < abs(n); i++)
        {
            res *= x;
        }
        if (n < 0)
            res = 1 / res;
    }
    
    return res;
}