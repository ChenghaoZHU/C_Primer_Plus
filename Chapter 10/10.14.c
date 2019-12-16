#include <stdio.h>

#define ROWS 3
#define COLS 5

void get_user_input(int, int, double [*][*]);
double average(int, const double [*]);
double total_average(int, int, const double [*][*]);
double max_val(int, int, const double [*][*]);

int main(void)
{
    double arr[ROWS][COLS];
    get_user_input(ROWS, COLS, arr);
    putchar('\n');
    for (int i = 0; i < ROWS; i++)
    {
        printf("Average of row %d is %.3lf\n", i + 1, average(COLS, arr[i]));
    }
    putchar('\n');
    printf("Total average of the array is %.3lf\n", total_average(ROWS, COLS, arr));
    putchar('\n');
    printf("The max value of the array is %.3lf\n", max_val(ROWS, COLS, arr));

    return 0;
}

double max_val(int rows, int cols, const double arr[rows][cols])
{
    double max = arr[0][0];
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            if (arr[r][c] > max)
                max = arr[r][c];
        }
    }
    return max;
}

double total_average(int rows, int cols, const double arr[rows][cols])
{
    double avg = 0.0;
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
            avg += arr[r][c];
    }
    return avg / cols / rows;
}

double average(int len, const double arr[len])
{
    double avg;
    avg = 0.0;
    for (int i = 0; i < len; i++)
    {
        avg += arr[i];
    }
    return avg / len;
}

void get_user_input(int rows, int cols, double arr[rows][cols])
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
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
        for (int c = 0; c < cols; c++)
        {
            printf("%.3lf ", arr[r][c]);
        }
        putchar('\n');
    }
}