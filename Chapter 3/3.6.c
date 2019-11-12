#include <stdio.h>

int main(void)
{
    int quarts;
    double m = 3e-23;  // mass of one water molecule
    int quart2grams = 950;

    printf("Input quarts: ");
    scanf("%d", &quarts);
    printf("Total water moluecue number is %e\n", quarts * quart2grams / m);

    return 0;
}