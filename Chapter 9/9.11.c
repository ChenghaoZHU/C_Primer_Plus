#include <stdio.h>
void Fibonacci(int);

int main(void)
{
    int n;
    printf("Enter an integer: ");
    while (scanf("%d", &n) == 1)
    {
        while (getchar() != '\n')
            continue;
        if (n <= 0)
        {
            printf("Enter an integer: ");
            continue;
        }
        printf("The sequence of fibonacci is ");
        Fibonacci(n);
        printf("Enter an integer: ");
    }
    printf("Bye.\n");
    return 0;
}

void Fibonacci(int n)
{
    int i, temp;
    int a = 1, b = 1;
    for (i = 0; i < n; i++)
    {
        printf("%d ", a);
        temp = a + b;
        a = b;
        b = temp;
    }
    printf("\n");
}