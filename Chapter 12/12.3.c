#include <stdio.h>

void set_mode(int *, int);
void get_info(int, float *, float *);
void show_info(int, float, float);

int main(void)
{
    float dist, fuel;
    int mode = 0;
    int m;

    printf("Enter 0 for metric mode, 1 for US mode: ");
    scanf("%d", &m);
    while (m >= 0)
    {
        set_mode(&mode, m);
        get_info(mode, &dist, &fuel);
        show_info(mode, dist, fuel);
        printf("Enter 0 for metric mode, 1 for US mode");
        printf(" (-1 to quit): ");
        scanf("%d", &m);
    }
    printf("Done.\n");
    return 0;
}

void show_info(int mode, float dist, float fuel)
{
    if (mode)
        printf("Fuel consumption is %.1f miles per gallon.\n", dist / fuel);
    else
        printf("Fuel consumption is %.1f liters per 100 km.\n", 100 * fuel / dist);
}

void set_mode(int * mode, int m)
{
    if (m != 0 && m != 1)
    {
        if (*mode == 0)
            puts("Invalid mode specified. Mode 0(metric) used.");
        else
            puts("Invalid mode specified. Mode 1(US) used.");
    } 
    else
        *mode = m;
}

void get_info(int mode, float * dist, float * fuel)
{
    if (mode)
    {
        printf("Enter distance traveled in miles: ");
        scanf("%f", dist);
        printf("Enter fuel consumed in gallons: ");
        scanf("%f", fuel);
    }
    else
    {
        printf("Enter distance traveled in killometers: ");
        scanf("%f", dist);
        printf("Enter fuel consumed in liters: ");
        scanf("%f", fuel);
    }
}