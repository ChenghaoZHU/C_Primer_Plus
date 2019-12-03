#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int ch;
    int upp_cnt = 0, low_cnt = 0;
    printf("Enter some text: \n");
    while ((ch = getchar()) != EOF)
    {
        if (isupper(ch))
            upp_cnt++;
        else if (islower(ch))
            low_cnt++;
    }
    printf("There are %d upper case characters and %d lower case characters.\n", upp_cnt, low_cnt);
    return 0;
}