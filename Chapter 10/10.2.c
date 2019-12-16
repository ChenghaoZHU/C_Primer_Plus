#include <stdio.h>

void copy_arr(double [], const double [], int);
void copy_ptr(double *, const double *, int);
void copy_ptrs(double [], const double [], double *);
void print_array(const double [], int);

int main(void)
{
    double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[5];
    double target2[5];
    double target3[5];

    printf("The source array is: ");
    print_array(source, 5);

    copy_arr(target1, source, 5);
    printf("The target1 array is: ");
    print_array(target1, 5);

    copy_ptr(target2, source, 5);
    printf("The target2 array is: ");
    print_array(target2, 5);

    copy_ptrs(target3, source, source + 5);
    printf("The target3 array is: ");
    print_array(target3, 5);

    return 0;
}

void print_array(const double array [], int length)
{
    int i;
    for (i = 0; i < length; i++)
        printf("%.1lf ", array[i]);
    printf("\n");
}

void copy_ptrs(double target [], const double source [], double * end)
{
    while (target < end)
    {
        *target++ = *source++;
    }
}

void copy_ptr(double * target, const double * source, int length)
{
    int i;
    for (i = 0; i < length; i++)
    {
        *target++ = *source++;
    }
}

void copy_arr(double target [], const double source [], int length)
{
    int i;
    for (i = 0; i < length; i++)
    {
        target[i] = source[i];
    }
}