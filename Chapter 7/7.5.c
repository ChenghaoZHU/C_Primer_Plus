#include <stdio.h>

int main(void)
{
    int n_replace = 0;
    char ch;
    printf("Enter some text (# to quit)\n");
    while ((ch = getchar()) != '#')
    {
        switch (ch)
        {
            case '.': putchar('!'); n_replace++; break;
            case '!': putchar('!'); n_replace++;
            default: putchar(ch);
        }
    }
    printf("\n%d replacements!\n", n_replace);
    return 0;
}