#include <stdio.h>
void copy_to_VLA(int, int, const double [*][*], double [*][*]);
void print_VAL(int, int, const double [*][*]);

int main(void)
{
    int rows, cols;
    double arr3x5[3][5] = {
        {1.1, 2.2, 3.3, 4.4, 5.5},
        {1.2, 2.3, 3.4, 4.5, 5.6},
        {1.3, 2.4, 3.5, 4.6, 5.7}
    };
    double dup[3][5];
    printf("The source array is: \n");
    print_VAL(3, 5, arr3x5);
    copy_to_VLA(3, 5, arr3x5, dup);
    printf("The target array is: \n");
    print_VAL(3, 5, dup);

    printf("Subset of target array is: \n");
    print_VAL(2, 4, dup);  // dup本身是一个指向五个int的指针，传入函数后，被转换成指向4个int的指针。

    return 0;
}

void copy_to_VLA(int rows, int cols, const double src[rows][cols], double tgt[rows][cols])
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            tgt[r][c] = src[r][c];   
        }
    }
}

void print_VAL(int rows, int cols, const double val[rows][cols])
{
    printf("rows is %d, cols is %d\n", rows, cols);
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            printf("%.1lf ", val[r][c]);
        }
        printf("\n");
    }
}