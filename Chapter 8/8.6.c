#include <stdio.h>

char get_first(void);

int main(void)
{
    char ch;
    printf("Enter some text: \n");
    while ((ch = get_first()) != '#')
        printf("The first letter in this line is %c\n", ch);
    return 0;
}

char get_first(void)
{
    int ch;
    while ((ch = getchar()) == ' ')
        continue;
    while (getchar() != '\n')
        continue;
    return (char)ch;
}