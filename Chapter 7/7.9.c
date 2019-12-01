#include <stdio.h>
#include <stdbool.h>

bool is_prime(unsigned int n);

int main(void)
{

    unsigned int n;
    unsigned int i;
    printf("Enter a positive integer: ");
    scanf("%u", &n);
    printf("The primes less than or equal to n are: \n");
    for (i = 0; i <= n; i++)
    {
        if (is_prime(i))
            printf("%u ", i);
    }
    printf("\n");

    return 0;
}

bool is_prime(unsigned int n)
{
    unsigned int i;
    if (n > 1)
    {
        for (i = 2; i * i <= n; i++) 
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    return false;
}