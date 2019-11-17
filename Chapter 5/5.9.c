#include <stdio.h>

void Temperatures(double fah);

int main(void)
{
    double fahrenheit;
    int input;
    printf("Enter your Fahrenheit temperature: ");
    input = scanf("%lf", &fahrenheit);
    while (input == 1)
    {
        Temperatures(fahrenheit);
        printf("Enter next Fahrenheit temperature (q or other non numerics): ");
        input = scanf("%lf", &fahrenheit);
    }
    printf("Done\n");
    
    return 0;
}

void Temperatures(double fah)
{
    double cel, kel;
    const double cel_offset = - 32.0, kel_offset = 273.16;

    cel = 5.0 / 9.0 * (fah + cel_offset);
    kel = cel + kel_offset;

    printf("It's Fahrenheit %.2lf degrees,\n", fah);
    printf("which is equal to Celsius %.2lf degrees \n", cel);
    printf("and thermodynamic %.2lf degrees.\n", kel);
}