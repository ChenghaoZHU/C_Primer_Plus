#include <stdio.h>
void copy_arr(double [], const double [], int);
void print_array(const double [], int);

int main(void)
{
    double arr2d[3][3] = {
        {1, 2, 3}, {4, 5, 6}, {7, 8, 9}
    };
    double target[3][3];

    printf("Source array is: \n");
    for (int i = 0; i < 3; i++)
    {
        print_array(arr2d[i], sizeof(arr2d[i]) / sizeof(double));
        copy_arr(target[i], arr2d[i], sizeof(arr2d[i]) / sizeof(double));
    }

    printf("Target array is: \n");
    for (int i = 0; i < 3; i++)
    {
        print_array(target[i], sizeof(target[i]) / sizeof(double));
    }

    return 0;
}

void copy_arr(double target [], const double source [], int length)
{
    int i;
    for (i = 0; i < length; i++)
    {
        target[i] = source[i];
    }
}

void print_array(const double array [], int length)
{
    int i;
    for (i = 0; i < length; i++)
        printf("%.1lf ", array[i]);
    printf("\n");
}