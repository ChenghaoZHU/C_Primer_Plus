#include <stdio.h>
#define SIZE 8

int main(void)
{
    int i;
    double df1[SIZE], df2[SIZE], sum;
    sum = 0;
    printf("Enter %d double float: ", SIZE);
    for (i = 0; i < SIZE; i++)
    {
        scanf("%lf", &df1[i]);
        sum += df1[i];
        df2[i] = sum;
    }
    printf("They look like: \n");
    for (i = 0; i < SIZE; i++)
    {
        printf("%10.2lf", df1[i]);
    }
    printf("\n");

    for (i = 0; i < SIZE; i++)
    {
        printf("%10.2lf", df2[i]);
    }
    printf("\n");

    return 0;
}