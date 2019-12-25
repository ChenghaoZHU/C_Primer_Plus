#include <stdio.h>
#include <ctype.h>
#define SIZE 50

const char * contains(const char [], char);

int main(void)
{
    char str[SIZE], ch;
    const char * found;
    puts("Enter a string and a character: ");
    while (scanf("%s %c", str, &ch))
    {
        if (str[1] == '\0' && toupper(str[0]) == 'Q')
            break;
        while (getchar() != '\n')
            continue;
        if ((found = contains(str, ch)))
            printf("%c found in %s, the storage addr is %p\n", ch, str, found);
        else
            printf("%c not found in %s\n", ch, str);
        puts("Enter a string and a character(Enter q' 'xxx  to quit): ");
    }
    puts("Bye.");

    return 0;
}

const char * contains(const char str [], char ch)
{
    const char * cp = NULL;
    const char * strp = str;
    while (*strp != '\0' && *strp != ch)
        strp++;
    if (*strp)
        cp = strp;
    return cp;
}