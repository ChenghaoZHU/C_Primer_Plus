#include <stdio.h>
#include <float.h>

int main(void)
{
    double n = 1.0 / 3.0;
    float m = 1.0 / 3.0;

    printf("double is %.6f, float is %.6f.\n", n, m);
    printf("double is %.12f, float is %.12f.\n", n, m);
    printf("double is %.16f, float is %.16f.\n", n, m);

    printf("FLT_DIG is %d, DBL_DIG is %d.\n", FLT_DIG, DBL_DIG);

    return 0;
}