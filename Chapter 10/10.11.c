#include <stdio.h>

void print_array(const int [][5], int);
void double_array_values(int [][5], int);

int main(void)
{
    int arr[3][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15}
    };
    printf("The array is: \n");
    print_array(arr, sizeof(arr) / sizeof(arr[0]));
    double_array_values(arr, sizeof(arr) / sizeof(arr[0]));
    printf("Then double it: \n");
    print_array(arr, sizeof(arr) / sizeof(arr[0]));

    return 0;
}

void double_array_values(int arr[][5], int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < sizeof(arr[i]) / sizeof(int); j++)
        {
            arr[i][j] *= 2;
        }
    }
}

void print_array(const int arr[][5], int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < sizeof(arr[i]) / sizeof(int); j++)
        {
            printf("%2d ", arr[i][j]);
        }
        putchar('\n');
    }
}