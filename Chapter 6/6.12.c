#include <stdio.h>

int main(void)
{
    int items, i, k;
    double sum1, sum2;

    printf("Enter item number: ");
    scanf("%d", &items);
    while (items > 0)
    {
        sum1 = 1.0;
        sum2 = 1.0;
        k = -1;
        for (i = 1; i < items; i++, k *= -1)
        {
            sum1 += 1.0 / (i + 1);
            sum2 += 1.0 * k / (i + 1);
        }
        printf("%d items:\n", items);
        printf("The sum of Sequence 1 is %lf\n", sum1);
        printf("The sum of Sequence 2 is %lf\n", sum2);

        printf("Enter item number again(<=0 to quit): ");
        scanf("%d", &items);
    }
    printf("Done\n");

    return 0;
}