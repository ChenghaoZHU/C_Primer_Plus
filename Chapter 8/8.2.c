#include <stdio.h>
#define LINE_WIDTH 10

int main(void)
{
    int ch;
    int count = 0;
    printf("Enter some text\n");
    while ((ch = getchar()) != EOF)
    {
        count++;
        if ((int)ch >= ' ' || ch == '\n' || ch == '\t')
        {
            printf("%c: %d ", ch, (int)ch);
        }
        else
        {
            printf("^%c: %d ", (char)(ch + 64), (int)ch);
        }
        if (ch == '\n')
            count = 0;
        if (count % LINE_WIDTH == 0)
            printf("\n");
    }
    return 0;
}