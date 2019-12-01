#include <stdio.h>
#define TAX_RATE1 0.15
#define TAX_RATE2 0.28
#define THRESHOLD1 17850.0
#define THRESHOLD2 23900.0
#define THRESHOLD3 29750.0
#define THRESHOLD4 14875.0

int main(void)
{
    int type;
    float salary, tax, threshold;
    printf("Enter your tax type and salary: \n");
    printf("1 for single, 2 for holder, 3 for marriged share and 4 for divore\n");
    while (scanf("%d %f", &type, &salary) == 2)
    {
        switch (type)
        {
            case 1: threshold = THRESHOLD1; break;
            case 2: threshold = THRESHOLD2; break;
            case 3: threshold = THRESHOLD3; break;
            case 4: threshold = THRESHOLD4; break;
            default: printf("Invalid type, please enter valid number\n"); type = -1;
        }
        if (type == -1)
            continue;

        printf("Your total salary is %.2f dollars.\n", salary);
        if (salary <= threshold)
            tax = salary * TAX_RATE1;
        else
            tax = TAX_RATE1 * threshold + (salary - threshold) * TAX_RATE2;
        printf("Your tax is %.2f dollars.\n", tax);
        
        printf("Enter your tax type and salary: \n");
        printf("1 for single, 2 for holder, 3 for marriged share and 4 for divore\n");
    }
    return 0;
}