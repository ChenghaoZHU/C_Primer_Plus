#include <stdio.h>
#include <string.h>
#define SIZE 50

void str_reverse(char *);
char * get_input(char *, int, FILE *);

int main(void)
{
    char str[SIZE];
    puts("Enter a string: ");
    while (get_input(str, SIZE, stdin))
    {
        printf("Origin str is %s\n", str);
        str_reverse(str);
        printf("Reversed str is %s\n", str);
        puts("Enter a string(Ctr^D to quit for unix): ");
    }
    puts("Bye.");
    return 0;
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

void str_reverse(char * str)
{
    char temp;
    char * head = str, * tail = str + strlen(str) - 1;
    while (head < tail)
    {
        temp = *head;
        *head = *tail;
        *tail = temp;  // swap
        head++;
        tail--;
    }
}