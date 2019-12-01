#include <stdio.h>

int main(void)
{
    int n;
    int n_even, n_odd, sum_even, sum_odd;
    n_even = n_odd = sum_even = sum_odd;
    printf("Enter integers(0 to quit)\n");
    while ((scanf("%d", &n) == 1) && n != 0)
    {
        if (n % 2 == 0)
        {
            n_even++;
            sum_even += n;
        }
        else
        {
            n_odd++;
            sum_odd += n;
        }
    }
    if (n_even)
    {
        printf("%d even numbers, average is %.2f\n", n_even, (float)sum_even / n_even);
    }
    else
    {
        printf("No even data\n");
    }
    if (n_odd)
    {
        printf("%d odd numbers, average is %.2f\n", n_odd, (float)sum_odd / n_odd);
    }
    else
    {
        printf("No odd data\n");
    }

    return 0;
}