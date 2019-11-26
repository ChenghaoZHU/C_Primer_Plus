#include <stdio.h>
#define SIZE 8

int powerOfTwo(int exp);

int main(void)
{
    int i;
    int powers[SIZE];
    
    printf("%d powers of two are: \n", SIZE);
    for (i = 0; i < SIZE; i++)
    {
        powers[i] = powerOfTwo(i);
    }
    i = 0;
    do
    {
        printf("%d ", powers[i]);
    } while (++i < SIZE);
    printf("\n");

    return 0;
}

int powerOfTwo(int exp)
{
    int i, power;
    power = 2;
    for (i = 0; i < exp; i++)
    {
        power *= 2;
    }

    return power;
}