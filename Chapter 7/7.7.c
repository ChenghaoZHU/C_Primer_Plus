#include <stdio.h>
#define BASE_SALARY 10.00
#define BASE_WORKTIME 40
#define RATE1 0.15
#define RATE2 0.20
#define RATE3 0.25
#define BREAK1 300
#define BREAK2 450
#define TAX_BASE1 RATE1 * BREAK1
#define TAX_BASE2 TAX_BASE1 + RATE2 * (BREAK2 - BREAK1)

int main(void)
{
    float hpw;  // hours per week
    float total, tax, income;
    printf("Enter hours you worked for last week.\n");
    scanf("%f", &hpw);
    printf("You worked %.2f hours last week\n", hpw);
    if (hpw > BASE_WORKTIME)
        hpw = BASE_WORKTIME + 1.5 * (hpw - BASE_WORKTIME);
    total = BASE_SALARY * hpw;
    if (total <= BREAK1)
        tax = total * RATE1;
    else if (total <= BREAK2)
        tax = TAX_BASE1 + RATE2 * (total - BREAK1);
    else
        tax = TAX_BASE2 + RATE3 * (total - BREAK2);
    income = total - tax;
    printf("Your total salary is %.2f dollars, tax is %.2f dollars, finally you get %.2f dollars.\n", total, tax, income);

    return 0;
}