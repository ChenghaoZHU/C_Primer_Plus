#include <stdio.h>
#define FUNCN 4

void show_menu(void);
void eatline(void);
int get_op(void);
int add(int, int);
int sub(int, int);
int mul(int, int);
int div(int, int);

int main(void)
{
    int (* func_arr[FUNCN]) (int, int) = {
        add, sub, mul, div
    };
    int op;
    int a, b;
    while ((op = get_op()) != -1)
    {
        if (op >= 0 && op < FUNCN)
        {
            printf("Enter two integers: ");
            while (scanf("%d %d", &a, &b) != 2)
            {
                eatline();
                printf("Enter two integers: ");
            }
            eatline();
            printf("a: %d b: %d\n", a, b);
            printf("The result is %d\n", func_arr[op](a, b));
        }
    }
    puts("Bye.");

    return 0;
}

void eatline(void)
{
    while (getchar() != '\n')
        continue; 
}

int get_op(void)
{
    int op;
    show_menu();
    while (scanf("%d", &op) != 1)
    {
        eatline();
        show_menu();
    }
    eatline();
    return op - 1;
}

void show_menu(void)
{
    printf("Choose one of the following operator (0 to quit): \n");
    printf("1) +         2) -       \n");
    printf("3) *         4) /       \n");
}

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int mul(int a, int b)
{
    return a * b;
}

int div(int a, int b)
{
    if (b == 0)
    {
        fputs("Divisor cannot be zero.\n", stderr);
        return 0;
    }
    return a / b;
}