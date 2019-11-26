#include <stdio.h>
int range_squared_sum(int lower, int upper);

int main(void)
{
    int lower, upper;
    printf("Enter lower and upper integer limits: ");
    scanf("%d %d", &lower, &upper);
    while (lower < upper)
    {
        printf("The sums of the squares from %d to %d is %d\n", lower, upper, range_squared_sum(lower, upper));
        printf("Enter next set of limits: ");
        scanf("%d %d", &lower, &upper);
    }
    printf("Done\n");
    
    return 0;
}

int range_squared_sum(int lower, int upper)
{
    /* return quared sum between lower and upper */
    int i, sum;
    sum = 0;
    for (i = lower; i <= upper; i++)
    {
        sum += i * i;
    }
    return sum;
}