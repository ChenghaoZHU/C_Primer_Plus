#include <stdio.h>

int main(void)
{
    int years = 0;
    float total = 1000000.0, interest = 0.08, out = 100000.0;
    while (total >= 0)
    {
        total *= 1 + interest;
        total -= out;
        printf("%d years later, Chuckie still has %.2f dollars\n", ++years, total);
    }
    printf("%d years later, Chuckie will run out of savings.\n", years);

    return 0;
}