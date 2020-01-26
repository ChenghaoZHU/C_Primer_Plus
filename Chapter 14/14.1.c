#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 10

struct month
{
    char name[10];
    char abbr[4];
    unsigned int days;
    unsigned int id;
};

struct month months[12] = {
    {"January", "JAN", 31, 1},
    {"Feburary", "FEB", 28, 2},
    {"March", "MAR", 31, 3},
    {"April", "APR", 30, 4},
    {"May", "MAY", 31, 5},
    {"June", "JUN", 30, 6},
    {"July", "JUL", 31, 7},
    {"August", "AUG", 31, 8},
    {"September", "SEP", 30, 9},
    {"October", "OCT", 31, 10},
    {"November", "NOV", 30, 11},
    {"December", "DEC", 31, 12}
};

int get_days(const char *);
char * s_gets(char *, int);
void eatline(void);
void ToUpper(char *);

int main(void)
{
    char name[MAX];
    printf("Enter month name: ");
    while (s_gets(name, MAX) != NULL && name[0] != '\0')
    {
        printf("In a year there are %d days from the first day to %s\n", get_days(name), name);
        printf("Enter month name (empty line to quit): ");
    }
    puts("Bye.");
    
    return 0;
}

void eatline(void)
{
    while (getchar() != '\n')
        continue;
}

char * s_gets(char * buff, int n)
{
    char * input;
    input = fgets(buff, n, stdin);
    if (input)
    {
        char * found = strchr(input, '\n');
        if (found)
            *found = '\0';
        else
            eatline();
    }
    return input;
}

void ToUpper(char * str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
    
}

int get_days(const char * name)
{
    int days = 0;
    char copy[MAX], buff[MAX];
    struct month m;
    for (int i = 0; i < 12; i++)
    {
        m = months[i];
        days += m.days;
        strcpy(copy, m.name);
        strcpy(buff, name);
        ToUpper(copy);
        ToUpper(buff);
        if (strcmp(buff, copy) == 0)
            return days;
    }
    return 0;  // 没有这个月份
}