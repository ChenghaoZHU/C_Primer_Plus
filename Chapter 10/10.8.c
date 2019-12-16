#include <stdio.h>

void copy_arr(double [], const double [], int);
void print_array(const double [], int);

int main(void)
{
    double source[7] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
    double target[3];

    printf("Source array is: ");
    print_array(source, sizeof(source) / sizeof(double));
    copy_arr(target, source + 2, 3);
    printf("Target array is: ");
    print_array(target, sizeof(target) / sizeof(double));

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