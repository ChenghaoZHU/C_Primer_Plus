#include <stdio.h>

#define ROWS 3
#define COLS 5

void get_user_input(double [][COLS], int);
double average(const double [], int);
double total_average(const double [][COLS], int);
double max_val(const double [][COLS], int);

int main(void)
{
    double arr[ROWS][COLS];
    get_user_input(arr, ROWS);
    putchar('\n');
    for (int i = 0; i < ROWS; i++)
    {
        printf("Average of row %d is %.3lf\n", i + 1, average(arr[i], COLS));
    }
    putchar('\n');
    printf("Total average of the array is %.3lf\n", total_average(arr, ROWS));
    putchar('\n');
    printf("The max value of the array is %.3lf\n", max_val(arr, ROWS));

    return 0;
}

double max_val(const double arr[][COLS], int rows)
{
    double max = arr[0][0];
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < sizeof(arr[r]) / sizeof(double); c++)
        {
            if (arr[r][c] > max)
                max = arr[r][c];
        }
    }
    return max;
}

double total_average(const double arr[][COLS], int rows)
{
    double avg = 0.0;
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < sizeof(arr[r]) / sizeof(double); c++)
            avg += arr[r][c];
    }
    return avg / (sizeof(arr[0]) / sizeof(double)) / rows;
}

double average(const double arr[], int len)
{
    double avg;
    avg = 0.0;
    for (int i = 0; i < len; i++)
    {
        avg += arr[i];
    }
    return avg / len;
}

void get_user_input(double arr[][COLS], int rows)
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < sizeof(arr[r]) / sizeof(double); c++)
        {
            printf("Enter a double float for arr[%d][%d]: ", r, c);
            while (scanf("%lf", &arr[r][c]) != 1)
            {
                while (getchar() != '\n')
                    continue;
                continue;
            }
            while (getchar() != '\n')
                continue;
        }
    }
    printf("Your input is: \n");
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < sizeof(arr[r]) / sizeof(double); c++)
        {
            printf("%.3lf ", arr[r][c]);
        }
        putchar('\n');
    }
}