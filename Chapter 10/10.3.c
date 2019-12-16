#include <stdio.h>

int max_int(const int arr [], int length);

int main(void)
{
    int a[5] = {1, 2, 3, 4, 5};
    int b[3] = {-19, 100, 20};
    int c[8] = {21, 31, 12, 36, 89, 45, 42, 60};
    int d[] = {2, 3, 77, 44, 33, 344, 788, 22, 57, 871, 2112};
    printf("Max value of a is %d\n", max_int(a, sizeof(a) / sizeof(int)));
    printf("Max value of b is %d\n", max_int(b, sizeof(b) / sizeof(int)));
    printf("Max value of c is %d\n", max_int(c, sizeof(c) / sizeof(int)));
    printf("Max value of d is %d\n", max_int(d, sizeof(d) / sizeof(int)));

    return 0;
}

int max_int(const int arr [], int length)
{
    int i, max;
    for (i = 1, max = arr[0]; i < length; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}