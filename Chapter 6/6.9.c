#include <stdio.h>
float cal(float f1, float f2);

int main(void)
{
    float f1, f2;  // two float numbers
    printf("Enter two float numbers: ");
    while (scanf("%f %f", &f1, &f2) == 2)
    {
        printf("f1: %f, f2: %f, ", f1, f2);
        printf(" their differences divided by their product is %f.\n", cal(f1, f2));
        printf("Enter two float numbers again(non-numeric input to exit): ");
    }
    
    return 0;
}

float cal(float f1, float f2)
{
    return (f1 - f2) / (f1 * f2);
}