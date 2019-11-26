#include <stdio.h>

int main(void)
{
    int i;
    char line[255];

    while (1)
    {
        printf("Enter a line: ");
        i = 0;
        while (scanf("%c", &line[i]) && line[i++] != '\n')
        ;
        printf("Line in reverse is: ");
        for (i -= 1; i >=0 ; i--)
        {
            printf("%c", line[i]);
        }
        printf("\n");
    }

    return 0;
}