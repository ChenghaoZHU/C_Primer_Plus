#include <stdio.h>

int main(void)
{
    int count, sum, n;
    
    printf("Enter number n: ");
    scanf("%d", &n);

    count = 0;
    sum = 0;
    while (count++ < n)
    {
        sum += count * count;
    }
    printf("sum = %d\n", sum);
    
    return 0;
}