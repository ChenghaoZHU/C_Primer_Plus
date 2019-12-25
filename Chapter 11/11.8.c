#include <stdio.h>
#include <ctype.h>
#define SIZE 50
const char * string_in(const char *, const char *);

int main(void)
{
    char str[SIZE], sub[SIZE], ch;
    const char * found;
    puts("Enter two stings(string, substring): ");
    while (scanf("%s %s", str, sub))
    {
        while ((ch = getchar()) != '\n')
        {
            if (toupper(ch) == 'Q')
                goto end;
        }
        printf("string: %s\n", str);
        printf("substring: %s\n", sub);
        if ((found = string_in(str, sub)))
        {
            printf("Found: %s started at %p\n", found, found);
        }
        else
        {
            puts("Not found");
        }
        puts("Enter two stings(string, substring): ");
        puts("Enter two strings with an extra q to quit(string, substring, 'q'): ");
    }
    end: printf("Bye.\n");

    return 0;
}

const char * string_in(const char * str, const char * sub)
{
    const char * found = NULL;
    int i = 0, j = 0;
    while (str[i] && sub[j])
    {
        if (str[i] == sub[j])
        {
            if (!found)
                found = str + i;
            j++;
        }
        else 
        {
            found = NULL;
            j = 0;
        }
        i++;
    }
    return found;
}