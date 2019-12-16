#include <stdio.h>

double max_min_diff(const double [], int);

int main(void)
{
    double test1[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double test2[3] = {9.4, 10.2, 2.3};
    double * test3 = (double []) {5.5, 4.6, 6.7, 3.2};  // 复合字面量 C99标准
    printf("The diff between max and min value of test1 is %.1lf\n", max_min_diff(test1, sizeof(test1) / sizeof(double)));
    printf("The diff between max and min value of test2 is %.1lf\n", max_min_diff(test2, sizeof(test2) / sizeof(double)));
    printf("The diff between max and min value of test3 is %.1lf\n", max_min_diff(test3, 4));
    
    return 0;
}

double max_min_diff(const double arr [], int len)
{
    int i;
    double max, min;
    for (i = 1, max = min = arr[0]; i < len; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }
    printf("max is %.1lf, min is %.1lf\n", max, min);
    return max - min;
}