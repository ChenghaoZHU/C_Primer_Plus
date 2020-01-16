#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

void clear(void);

int main(void)
{
    FILE * fp;
    int pos, ch;
    char file_name[SIZE];
    printf("Enter file name: ");
    scanf("%50s", file_name);
    clear();
    if ((fp = fopen(file_name, "r")) == NULL)
    {
        fprintf(stderr, "File %s cannot be opened.\n", file_name);
        exit(EXIT_FAILURE);
    }
    printf("Enter an file postion (negative or non numeric to quit): ");
    while ((scanf("%d", &pos) == 1) && pos >= 0) 
    {
        clear();
        fseek(fp, pos, SEEK_SET);
        while ((ch = getc(fp)) != '\n' && ch != EOF)
            putchar(ch);
        printf("\nEnter an file postion (negative or non numeric to quit): ");
    }
    if (fclose(fp) != 0)
    {
        fprintf(stderr, "File %s cannot be closed.\n", file_name);
        exit(EXIT_FAILURE);
    }
    printf("Bye.\n");
    return 0;
}

void clear(void)
{
    while (getchar() != '\n')
        continue;
}