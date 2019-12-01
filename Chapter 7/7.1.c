#include <stdio.h>

int main(void)
{
    char ch;
    int n_space = 0;  // number of spaces
    int n_newline = 0;  // number of newlines
    int n_other = 0;  // number of other characters

    printf("Enter some text; enter # to quit.\n");
    while ((ch = getchar()) != '#')
    {
        if (ch == ' ')
            n_space++;
        else if (ch == '\n')
            n_newline++;
        else
            n_other++;
    }
    printf("%d spaces, %d newlines and %d other characters.\n", n_space, n_newline, n_other);

    return 0;
}