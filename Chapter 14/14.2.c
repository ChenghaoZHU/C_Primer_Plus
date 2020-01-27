#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define LEN 10

union month_name
{
    unsigned int m_int;
    char m_str[LEN];
};


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

char * s_gets(char *, int);
void eatline(void);
void ToUpper(char *);
int get_days(int, int, union month_name, bool);
bool isLeapYear(int);

int main(void)
{
    union month_name m_name;
    bool flag = true;
    unsigned int year, day;
    printf("Enter year day and month (Ctl^D to quit): ");
    while (scanf("%u %u %u", &year, &day, &m_name.m_int) == 3 
            || (flag = false)
            || scanf("%s", m_name.m_str) == 1)
    {
        eatline();  // clear input
        printf("There are totally %d days from first day to specified date.\n",
                get_days(year, day, m_name, flag));
        printf("Enter year day and month (Ctl^D to quit): ");
        flag = true;
    }
    puts("Bye.");
    return 0;
}

bool isLeapYear(int year)
{
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
                return true;
            else
                return false;
        }
        return true;
    }
    else
        return false;
}

int get_days(int year, int day, union month_name month, bool flag)
{
    int days = 0;
    int m;  // 用来记录月份号
    char copy1[LEN], copy2[LEN];
    for (int i = 0; i < 12; i++)
    {
        if (flag && i + 1 == month.m_int)
        {
            m = month.m_int;
            break;
        } else
        {
            strcpy(copy1, month.m_str);
            strcpy(copy2, months[i].name);
            ToUpper(copy1);
            ToUpper(copy2);
            if (strcmp(copy1, copy2) == 0 || strcmp(copy1, months[i].abbr) == 0)
            {
                m = months[i].id;
                break;
            }            
        }
        days += months[i].days;
    }
    days += day;
    if (isLeapYear(year) && m > 2)
        days += 1;
    return days;
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
