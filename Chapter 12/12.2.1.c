#include <stdio.h>
#include "12.2.1.h"

static int mode = 0;  // 0 for metric mode, 1 for US mode
static float dist = 0.0;  // distance
static float fuel = 0.0;  // fuel consumed

void get_info(void)
{
    if (mode)
    {
        printf("Enter distance traveled in miles: ");
        scanf("%f", &dist);
        printf("Enter fuel consumed in gallons: ");
        scanf("%f", &fuel);
    }
    else
    {
        printf("Enter distance traveled in killometers: ");
        scanf("%f", &dist);
        printf("Enter fuel consumed in liters: ");
        scanf("%f", &fuel);
    }
}

void show_info(void)
{
    if (mode)
        printf("Fuel consumption is %.1f miles per gallon.\n", dist / fuel);
    else
        printf("Fuel consumption is %.1f liters per 100 km.\n", 100 * fuel / dist);
}

void set_mode(int m)
{
    if (m != 0 && m != 1)
    {
        if (mode == 0)
            puts("Invalid mode specified. Mode 0(metric) used.");
        else
            puts("Invalid mode specified. Mode 1(US) used.");
    } 
    else
        mode = m;
}