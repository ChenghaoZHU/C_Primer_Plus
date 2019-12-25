#include <stdio.h>
#include <string.h>
#define NUM 10
#define SIZE 50
#define DELIMITER "****************************************************************************"

char * get_input(char *, int, FILE *);
int get_option(void);
void show_menu(void);
void print_natural(char [][SIZE], int);
void print_ascii(char [][SIZE], int);
void print_length(char [][SIZE], int);
void print_first_word(char [][SIZE], int);
int get_first_word_length(char *);

int main(void)
{
    int op;
    int num = 0;
    char strs[NUM][SIZE];
    printf("Enter %d lines of strings: \n", NUM);
    while (num < NUM && get_input(strs[num], SIZE, stdin))
        num++;
    while ((op = get_option()) != 5)
    {
        switch (op)
        {
            case 1: print_natural(strs, num); break;
            case 2: print_ascii(strs, num); break;
            case 3: print_length(strs, num); break;
            case 4: print_first_word(strs, num); break;
        }
    }
    puts("Bye.");

    return 0;
}

void show_menu(void)
{
    puts(DELIMITER);
    puts("You can choose one of the following options to display the strings(1-5): ");
    printf("%-40s", "1. by natural sort");
    printf("%-40s\n", "2. by ascii sort");
    printf("%-40s", "3. by length ascending sort");
    printf("%-40s\n", "4. by length of first word");
    printf("%-40s\n", "5. quit");
    puts(DELIMITER);
}

int get_option(void)
{
    int op = 0;
    while (1)
    {
        show_menu();
        while (scanf("%d", &op) == EOF)
        {
            rewind(stdin);
        }
        while (getchar() != '\n')
            continue;
        if (op == 1 || op == 2 || op == 3 || op == 4 || op == 5)
            return op;
    }
}

char * get_input(char * str, int size, FILE * in)
{
    int i = 0;
    char * input = fgets(str, size, in);
    if (input)
    {
        while (input[i] != '\0')
        {
            if (input[i] == '\n')
            {
                input[i] = '\0';
                break;
            }
            i++;
        }
    }
    return input;
}

void print_natural(char strs[][SIZE], int rows)
{
    int i = 0;
    for (; i < rows; i++)
        puts(strs[i]);
}

void print_ascii(char strs[][SIZE], int rows)
{
    int i, j, min;
    char * sorted[NUM];
    char * temp;

    for (i = 0; i < rows; i++)
        sorted[i] = strs[i];

    for (i = 0; i < rows - 1; i++)
    {
        min = i;
        for (j = i + 1; j < rows; j++)
        {
            if (strcmp(sorted[j], sorted[min]) < 0)
                min = j;
        }
        if (min != i)
        {  // 交换
            temp = sorted[i];
            sorted[i] = sorted[min];
            sorted[min] = temp;
        }
    }

    for (i = 0; i < rows; i++)
        puts(sorted[i]);
}

void print_length(char strs[][SIZE], int rows)
{
    int i, j, min;
    char * sorted[NUM];
    char * temp;

    for (i = 0; i < rows; i++)
        sorted[i] = strs[i];

    for (i = 0; i < rows - 1; i++)
    {
        min = i;
        for (j = i + 1; j < rows; j++)
        {
            if (strlen(sorted[j]) < strlen(sorted[min]))
                min = j;
        }
        if (min != i)
        {  // 交换
            temp = sorted[i];
            sorted[i] = sorted[min];
            sorted[min] = temp;
        }
    }

    for (i = 0; i < rows; i++)
        puts(sorted[i]);
}

void print_first_word(char strs[][SIZE], int rows)
{
    int i, j, min;
    char * sorted[NUM];
    char * temp;

    for (i = 0; i < rows; i++)
        sorted[i] = strs[i];

    for (i = 0; i < rows - 1; i++)
    {
        min = i;
        for (j = i + 1; j < rows; j++)
        {
            if (get_first_word_length(sorted[j]) < get_first_word_length(sorted[min]))
                min = j;
        }
        if (min != i)
        {  // 交换
            temp = sorted[i];
            sorted[i] = sorted[min];
            sorted[min] = temp;
        }
    }

    for (i = 0; i < rows; i++)
        puts(sorted[i]);

}

int get_first_word_length(char * str)
{
    int head = 0, tail = 0;
    while (str[head] && str[head] == ' ')
        head++;
    tail = head;
    while (str[tail] && str[tail] != ' ')
        tail++;
    return tail - head;
}