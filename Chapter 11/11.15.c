#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define SIZE 200

char * get_line(char *);
int my_atoi(char *);

int main(void)
{
    char line[SIZE];
    puts("Enter a line: ");
    while (get_line(line))
    {
        printf("%s transfer to integer is %d\n", line, my_atoi(line));
        puts("Enter a line(Ctr^D to quit): ");
    }
    puts("Bye.");
    return 0;
}

int my_atoi(char * str)
{
    int i = 0;
    if (str[0] == '-')
        i++;
    while (str[i] && isdigit(str[i]))
        i++;
    if (str[i])
        return 0;
    return atoi(str);
}

char * get_line(char * line)
{
    int i = 0;
    char * l = fgets(line, SIZE, stdin);
    if (l)
    {
        while (line[i] && line[i] != '\n')
            i++;
        if (line[i] == '\n')
            line[i] = '\0';
    }
    return l;
}