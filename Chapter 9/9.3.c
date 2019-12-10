#include <stdio.h>
void chline(char ch, int i, int j);

int main(void)
{
    int i, j;
    char ch;
    printf("Enter a char and two integers(q to quit): ");
    while (scanf("%c %d %d", &ch, &i, &j) == 3)
    {
        chline(ch, i, j);
        while (getchar() != '\n')
            continue;
        printf("Enter a char and two integers(q to quit): ");
    }
    printf("Done.\n");
    
    return 0;
}

// print ch as a matrix of j lines with i columns.
void chline(char ch, int i, int j)
{
    int n, m;
    for (n = 0; n < j; n++) {
        for (m = 0; m < i; m++) {
            printf("%c", ch);
        }
        printf("\n");
    }
}