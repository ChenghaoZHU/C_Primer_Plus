#include <stdio.h>

int main(void)
{
    float height;
    float inch2cent = 2.54f;

    printf("Input your height: ");
    scanf("%f", &height);
    printf("Your height is %f centimeters.\n", height * inch2cent);

    return 0;
}