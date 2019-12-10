#include <stdio.h>
#include <ctype.h>

int char_position(char);


int main(void)
{
    char ch;
    int pos;
    printf("Enter some text: \n");
    while ((ch = getchar()) != EOF)
    {
        pos = char_position(ch);
        if (pos == -1)
            printf("%c is not alpha.\n", ch);
        else
            printf("%c is an alpha and its postion is %d.\n", ch, pos);
    }
    printf("Done.\n");
    return 0;
}

int char_position(char ch)
{   
    int pos = -1;
    if (isalpha(ch)) {
        pos = ch - 'a' >= 0 ? ch - 'a': ch - 'A';
        pos += 1;
    }
    return pos;
}