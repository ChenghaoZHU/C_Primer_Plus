#include <stdio.h>
#include <stdlib.h>

#define ROWS 20
#define COLS 30

void load_nums(FILE *, int [][COLS]);
void fix_nums(int [][COLS], int);
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
    fix_nums(nums, ROWS);
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

void fix_nums(int nums[][COLS], int rows)
{   
    puts("Original data: ");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < COLS; j++)
            printf("%d ", nums[i][j]);
        printf("\n");
    }
    int fixed[rows][COLS], temp;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            int top = 0, right = 0, bottom = 0, left = 0;
            if (i - 1 >= 0)
            {
                top = nums[i-1][j];
                temp = top - nums[i][j];
                if (temp >= -1 && temp <= 1)
                {
                    fixed[i][j] = nums[i][j];
                    continue;
                }   
            }
            if (j + 1 < COLS)
            {
                right = nums[i][j+1];
                temp = right - nums[i][j];
                if (temp >= -1 && temp <= 1)
                {
                    fixed[i][j] = nums[i][j];
                    continue;
                }   
            }
            if (i + 1 < rows)
            {
                bottom = nums[i+1][j];
                temp = bottom - nums[i][j];
                if (temp >= -1 && temp <= 1)
                {
                    fixed[i][j] = nums[i][j];
                    continue;
                }   
            }
            if (j - 1 >= 0)
            {
                left = nums[i][j-1];
                temp = left - nums[i][j];
                if (temp >= -1 && temp <= 1)
                {
                    fixed[i][j] = nums[i][j];
                    continue;
                }  
            }
            int count = 0;
            if (bottom != 0)
                count++;
            if (right != 0)
                count++;
            if (left != 0)
                count++;
            if (top != 0)
                count++;
            // fix
            fixed[i][j] = (int) ((float) (top + right + bottom + left) / count + 0.5);\
        }
    }
    // 复制
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < COLS; j++)
            nums[i][j] = fixed[i][j];
    
    puts("Fixed data: ");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < COLS; j++)
            printf("%d ", nums[i][j]);
        printf("\n");
    }
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