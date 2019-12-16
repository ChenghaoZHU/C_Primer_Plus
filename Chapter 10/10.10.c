#include <stdio.h>

void array_add(const int [], const int [], int [], int);
void print_array(const int [], int);

int main(void)
{
    int c[4];
    int a[4] = {2, 4, 5, 8}, b[4] = {1, 0, 4, 6};
    printf("a is ");
    print_array(a, sizeof(a) / sizeof(int));
    printf("b is ");
    print_array(b, sizeof(b) / sizeof(int));
    array_add(a, b, c, sizeof(a) / sizeof(int));
    printf("c is ");
    print_array(c, sizeof(c) / sizeof(int));

    return 0;
}

void array_add(const int arr1 [], const int arr2 [], int arr3 [], int len)
{
    for (int i = 0; i < len; i++)
    {
        arr3[i] = arr1[i] + arr2[i];
    }
}

void print_array(const int array [], int length)
{
    int i;
    for (i = 0; i < length; i++)
        printf("%d ", array[i]);
    printf("\n");
}