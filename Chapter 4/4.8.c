#include <stdio.h>

#define GALLON2LITER 3.875F
#define MILE2KM 1.609F

int main(void)
{
    float mileage, fuelConsum;
    printf("Enter mileage and fuel comsumption: ");
    scanf("%f %f", &mileage, &fuelConsum);

    printf("Miles per gallon: %.1f.\n", mileage / fuelConsum);
    printf("It's equal to %.1f liters per 100 kilometer.\n", fuelConsum * GALLON2LITER * 100 / (mileage * MILE2KM));

    return 0;
}