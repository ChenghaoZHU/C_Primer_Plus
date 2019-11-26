#include <stdio.h>

int main(void)
{
    int years;
    float assets1, assets2;
    float simple_interest, compound_interest, base;
    simple_interest = 0.1;
    compound_interest = 0.05;
    base = 100.0;
    assets1 = assets2 = base;
    years = 1;
    while (assets2 <= assets1)
    {
        assets1 += base * simple_interest;
        assets2 *= (1 + compound_interest);
        years++;
    }

    printf("%d years later, Derdre becomes richer than Daphne:\n", --years);
    printf("At that time, Derdre has %.2f dollars and Daphne has %.2f dollars\n", assets2, assets1);
    
    return 0;
}