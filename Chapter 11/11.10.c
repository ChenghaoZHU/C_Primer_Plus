#include <stdio.h>
#define SIZE 50

void eliminate_blanks(char *);
char * get_input(char *, int, FILE *);

int main(void)
{
    char str[SIZE];
    puts("Enter a string: ");
    while (get_input(str, SIZE, stdin))
    {
        printf("Origin str is %s\n", str);
        eliminate_blanks(str);
        printf("after deleting all blanks:\n str is %s\n", str);
        puts("Enter a string(Ctr^D to quit for unix): ");
    }
    puts("Bye.");
    return 0;
}

void eliminate_blanks(char * str)
{
    int i = 0, blank = 0;
    while (str[i])
    {
        if (str[i] == ' ')
        {
            blank++;
        }
        else
        {
            if (blank)
            {
                str[i - blank] = str[i];
            }       
        }
        i++;
    }
    str[i - blank] = '\0';
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