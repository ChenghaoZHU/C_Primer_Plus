#include <stdio.h>
#include <ctype.h>
#define SIZE 200

char * get_line(char *);

int main(int argc, char * argv[])
{
    char line[SIZE];
    char * op = "-p";
    char ch;
    int i = 0;
    if (argc > 1)
    {
        op = argv[1];
    }
    puts("Enter some text(Ctr^D to quit): ");
    while ((ch = getchar()) != EOF)
        line[i++] = ch;
    printf("Mode %s: \n", op + 1);
    i = 0;
    if (op[1] == 'l')
    {
        while (line[i])
            putchar(tolower(line[i++]));
        putchar('\n');
    }
    else if (op[1] == 'u')
    {
        while (line[i])
            putchar(toupper(line[i++]));
        putchar('\n');
    }
    else
        puts(line);

    puts("Done.");
    

    return 0;
}
