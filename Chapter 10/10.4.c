#include <stdio.h>

int max_value_pos(const double [], int);

int main(void)
{
    double test1[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double test2[3] = {9.4, 10.2, 2.3};
    double * test3 = (double []) {5.5, 4.6, 6.7, 3.2};  // 复合字面量 C99标准
    printf("Max value position of test1 is %d\n", max_value_pos(test1, sizeof(test1) / sizeof(double)));
    printf("Max value position of test2 is %d\n", max_value_pos(test2, sizeof(test2) / sizeof(double)));
    printf("Max value position of test3 is %d\n", max_value_pos(test3, 4));

    return 0;
}

int max_value_pos(const double arr [], int length)
{
    int i, max;
    int pos = -1;
    if (length < 0)
        return pos;
    else
        pos = 0;

    for (i = 1, max = arr[pos]; i < length; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            pos = i;
        }
    }
    return pos;
}