#include <stdio.h>
#include <stdlib.h>

#define ROWS 20
#define COLS 30

void load_nums(FILE *, int rows, int cols, int nums[rows][cols]);
void print_strs(int rows, int cols, char strs[rows][cols]);
void convert_num2str(int rows, int cols, int nums[rows][cols], char strs[rows][cols + 1]);
void save_strs(FILE *, int rows, int cols, char strs[rows][cols]);

int main(void)
{
    FILE * fp;
    char fileName[50], strs[ROWS][COLS + 1];
    int nums[ROWS][COLS];
    printf("Enter file name: ");
    scanf("%50s", fileName);
    if ((fp = fopen(fileName, "r")) == NULL)
    {
        fprintf(stderr, "Cannot open %s\n", fileName);
        exit(EXIT_FAILURE);
    }
    load_nums(fp, ROWS, COLS, nums);
    if (fclose(fp) != 0)
    {
        fprintf(stderr, "Cannot close %s\n", fileName);
        exit(EXIT_FAILURE);
    }
    convert_num2str(ROWS, COLS, nums, strs);
    print_strs(ROWS, COLS + 1, strs);
    printf("Enter file name to save image: ");
    scanf("%50s", fileName);
    if ((fp = fopen(fileName, "w")) == NULL)
    {
        fprintf(stderr, "Cannot open %s\n", fileName);
        exit(EXIT_FAILURE);
    }
    save_strs(fp, ROWS, COLS + 1, strs);
    if (fclose(fp) != 0)
    {
        fprintf(stderr, "Cannot close %s\n", fileName);
        exit(EXIT_FAILURE);
    }
    return 0;
}

void save_strs(FILE * fp, int rows, int cols, char strs[rows][cols])
{
    for (int i = 0; i < rows; i++)
        fprintf(fp, "%s\n", strs[i]);
}

void print_strs(int rows, int cols, char strs[rows][cols])
{
    for (int i = 0; i < rows; i++)
        printf("%s\n", strs[i]);
}

void convert_num2str(int rows, int cols, int nums[rows][cols], char strs[rows][cols + 1])
{
    for (int r = 0; r < rows; r++)
    {
        int c = 0;
        for (c = 0; c < cols; c++)
        {
            switch (nums[r][c])
            {
                case 0: strs[r][c] = ' '; break;
                case 1: strs[r][c] = '.'; break;
                case 2: strs[r][c] = '\''; break;
                case 3: strs[r][c] = ':'; break;
                case 4: strs[r][c] = '~'; break;
                case 5: strs[r][c] = '*'; break;
                case 6: strs[r][c] = '='; break;
                case 7: strs[r][c] = '@'; break;
                case 8: strs[r][c] = '%'; break;
                case 9: strs[r][c] = '#'; break;
            }
        }
        strs[r][c] = '\0';
    }
}

void load_nums(FILE * fp, int rows, int cols, int nums[rows][cols])
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            fscanf(fp, "%d", &nums[r][c]);
        }
    }
}