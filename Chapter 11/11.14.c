#include <stdio.h>
#include <stdlib.h>
double power_d(double, int);

int main(int argc, char * argv [])
{
    if (argc < 3)
        return -1;
    char * temp;
    double x = strtol(argv[1], &temp, 10);
    int n = strtod(argv[2], &temp);
    printf("The %lf to the power of %d is %.4lf\n", x, n, power_d(x, n));
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