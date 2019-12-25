#include <stdio.h>
#define SIZE 50

int is_within(char, const char *);

int main(void)
{
    char str[SIZE], ch;
    puts("Enter a string and a character: ");
    while (scanf("%s %c", str, &ch))
    {
        while (getchar() != '\n')
            continue;
        if (str[0] == '|' && str[1] == '|')
            break;
        if (is_within(ch, str))
            printf("%c in %s\n", ch, str);
        else
            printf("%c not in %s\n", ch, str);
        puts("Enter a string and a character(string starts with '||' to quit): ");
    }
    puts("Bye.");
    return 0;
}

int is_within(char ch, const char * sp)
{
    int found = 0;
    while (*sp && *sp++ != ch)
        continue;
    if (*sp)
        found = 1;

    return found;
}