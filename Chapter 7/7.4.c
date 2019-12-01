#include <stdio.h>

int main(void)
{
    int n_replace = 0;
    char ch;
    printf("Enter some text (# to quit)\n");
    while ((ch = getchar()) != '#')
    {
        if (ch == '.')
        {
            n_replace++;
            putchar('!');
        }
        else
        {
            if (ch == '!')
            {
                n_replace++;
                putchar(ch);
            }
            putchar(ch);
        }
    }
    printf("\n%d replacements!\n", n_replace);

    return 0;
}