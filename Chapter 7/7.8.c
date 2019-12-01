#include <stdio.h>
#define LINEDELIMITER "******************************************************"
#define PAYRATE1 8.75
#define PAYRATE2 9.33
#define PAYRATE3 10.00
#define PAYRATE4 11.20

#define BASE_WORKTIME 40
#define RATE1 0.15
#define RATE2 0.20
#define RATE3 0.25
#define BREAK1 300
#define BREAK2 450
#define TAX_BASE1 RATE1 * BREAK1
#define TAX_BASE2 TAX_BASE1 + RATE2 * (BREAK2 - BREAK1)

int show_menu();

int main(void)
{
    int op;
    float pay_rate;
    float hpw;  // hours per week
    float total, tax, income;
    while ((op = show_menu()) != 5)
    {
        switch (op)
        {
            case 1: pay_rate = PAYRATE1; break;
            case 2: pay_rate = PAYRATE2; break;
            case 3: pay_rate = PAYRATE3; break;
            case 4: pay_rate = PAYRATE4; break;
            default: break;
        }
        if (op == -1)
        {
            printf("Please input valid option 1-5\n");
            continue;
        }
        printf("Enter hours you worked for last week.\n");
        scanf("%f", &hpw);
        printf("You worked %.2f hours last week for pay rate %.2f\n", hpw, pay_rate);
        if (hpw > BASE_WORKTIME)
            hpw = BASE_WORKTIME + 1.5 * (hpw - BASE_WORKTIME);
        total = pay_rate * hpw;
        if (total <= BREAK1)
            tax = total * RATE1;
        else if (total <= BREAK2)
            tax = TAX_BASE1 + RATE2 * (total - BREAK1);
        else
            tax = TAX_BASE2 + RATE3 * (total - BREAK2);        
        income = total - tax;
        printf("Your total salary is %.2f dollars, tax is %.2f dollars, finally you get %.2f dollars.\n", total, tax, income);
    }
    printf("Bye.\n");
    return 0;
}

int show_menu()
{
    int op;
    printf("%s\n", LINEDELIMITER);
    printf("Enter the number corresponding to the desired pay rate or action:\n");
    printf("1) $%.2f/hr %20s", PAYRATE1, "");
    printf("2) $%.2f/hr %20s", PAYRATE2, "\n");
    printf("3) $%.2f/hr %20s", PAYRATE3, "");
    printf("4) $%.2f/hr %20s", PAYRATE4, "\n");
    printf("5) quit %20s", "\n");
    printf("%s\n", LINEDELIMITER);
    scanf("%d", &op);
    if (op < 1 || op > 5)
        op = -1;
    return op;
}