#include <stdio.h>
#define RESULT "%.3f %c %.3f = %.3f\n"

char get_operation(void);
float get_float(void);

int main(void)
{
    float x, y;
    char op;

    while ((op = get_operation()) != 'q')
    {
        printf("Enter first number: ");
        x = get_float();
        printf("Enter second number: ");
        while (1)
        {
            y = get_float();
            if ( y == 0 && op == 'd')
            {
                printf("Enter a number other than 0: ");
                continue;
            }
            break;
        }

        switch (op)
        {
            case 'a': printf(RESULT, x, '+', y, x + y); break;
            case 's': printf(RESULT, x, '-', y, x - y); break;
            case 'm': printf(RESULT, x, '*', y, x * y); break;
            case 'd': printf(RESULT, x, '/', y, x / y); break;
            default: break;
        }
    }
    printf("Bye.\n");

    return 0;
}

float get_float(void)
{
    float f;
    int ch;
    while (scanf("%f", &f) != 1)
    {
        while ((ch = getchar()) != '\n')
            putchar(ch);
        printf(" is not a number.\nPlease enter a number, such as 2.5, -1.78E8, or 3: ");
    }
    while (getchar() != '\n')
        continue;
    return f;
}

char get_operation(void)
{
    int op;
    do
    {
        printf("Enter the operation of your choice:\n"
               "a. add           s. subtract\n"
               "m. multiply      d. divide\n"
               "q. quit\n");
        op = getchar();
        while (getchar() != '\n')
            continue;
        if (op == 'a' || op == 's' || op == 'm' || op == 'd' || op == 'q')
            return (char)op;
        else
            printf("Invalid option: %c\n", op);
    } while (1);
}