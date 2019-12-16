#include <stdio.h>

void reverse_array(double [], int);
void print_array(const double [], int);


int main(void)
{
    double test1[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double test2[3] = {9.4, 10.2, 2.3};
    double * test3 = (double []) {5.5, 4.6, 6.7, 3.2};  // 复合字面量 C99标准

    printf("Original array is: ");
    print_array(test1, sizeof(test1) / sizeof(double));
    reverse_array(test1, sizeof(test1) / sizeof(double));
    printf("Reversed array is: ");
    print_array(test1, sizeof(test1) / sizeof(double));

    printf("Original array is: ");
    print_array(test2, sizeof(test2) / sizeof(double));
    reverse_array(test2, sizeof(test2) / sizeof(double));
    printf("Reversed array is: ");
    print_array(test2, sizeof(test2) / sizeof(double));


    printf("Original array is: ");
    print_array(test3, 4);
    reverse_array(test3, 4);
    printf("Reversed array is: ");
    print_array(test3, 4);

    return 0;
}

void reverse_array(double arr [], int len)
{
    double temp;
    double * s, * e;
    s = arr;
    e = s + len - 1;
    do
    {
        temp = *s;
        *s = *e;
        *e = temp;
    } while (++s < --e);
}

void print_array(const double arr [], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%.3lf ", arr[i]);
    }
    putchar('\n');
}