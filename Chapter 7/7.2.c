#include <stdio.h>
#define LINE_LEN 8

int main(void)
{
    char ch;
    int char_count = 0;

    printf("Enter some text, # to quit\n");
    while ((ch = getchar()) != '#')
    {
        char_count++;
        putchar(ch);
        printf(" %-5d", ch);
        if (char_count % LINE_LEN == 0) {
            printf("\n");
        }
    }

    return 0;
}