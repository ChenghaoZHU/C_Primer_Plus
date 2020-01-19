#include <stdio.h>
#include <stdlib.h>

#define ROWS 20
#define COLS 30

void load_nums(FILE *, int [][COLS]);
void print_strs(char [][COLS + 1]);
void convert_num2str(int [][COLS], char [][COLS + 1]);
void save_strs(FILE *, char [][COLS + 1]);

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
    load_nums(fp, nums);
    if (fclose(fp) != 0)
    {
        fprintf(stderr, "Cannot close %s\n", fileName);
        exit(EXIT_FAILURE);
    }
    convert_num2str(nums, strs);
    print_strs(strs);
    printf("Enter file name to save image: ");
    scanf("%50s", fileName);
    if ((fp = fopen(fileName, "w")) == NULL)
    {
        fprintf(stderr, "Cannot open %s\n", fileName);
        exit(EXIT_FAILURE);
    }
    save_strs(fp, strs);
    if (fclose(fp) != 0)
    {
        fprintf(stderr, "Cannot close %s\n", fileName);
        exit(EXIT_FAILURE);
    }
    return 0;
}

void save_strs(FILE * fp, char strs[][COLS + 1])
{
    for (int i = 0; i < ROWS; i++)
        fprintf(fp, "%s\n", strs[i]);
}

void print_strs(char strs[][COLS + 1])
{
    for (int i = 0; i < ROWS; i++)
        printf("%s\n", strs[i]);
}

void convert_num2str(int nums[][COLS], char strs[][COLS + 1])
{
    for (int r = 0; r < ROWS; r++)
    {
        int c = 0;
        for (c = 0; c < COLS; c++)
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

void load_nums(FILE * fp, int nums[][COLS])
{
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            fscanf(fp, "%d", &nums[r][c]);
        }
    }
}