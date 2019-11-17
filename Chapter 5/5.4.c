#include <stdio.h>
#define INCH2CM 2.54
#define FEET2INCHES 12

int main(void)
{
    float height, inches;
    int feet;

    printf("Enter a height in centimeters: ");
    scanf("%f", &height);
    while (height > 0)
    {
        inches = height / INCH2CM;
        feet = (int)inches / FEET2INCHES;
        printf("%.1f cm = %d feet, %.1f inches\n", height, feet, inches - feet * FEET2INCHES);
        printf("Enter a height in centimeters (<=0 to quit): ");
        scanf("%f", &height);
    }
    printf("bye\n");
    

    return 0;
}