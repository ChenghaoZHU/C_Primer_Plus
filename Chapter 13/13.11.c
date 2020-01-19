#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 255

char * getLine(FILE *, char []);

int main(int argc, char * argv[])
{
    FILE * fp;
    char buff[MAX], * line;
    if (argc < 3)
    {
        fputs("Argument number is less than 3.\n", stderr);
        exit(EXIT_FAILURE);
    }
    if ((fp = fopen(argv[2], "r")) == NULL)
    {
        fprintf(stderr, "File %s cannot be opened.\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    while ((line = getLine(fp, buff)) != NULL)
    {
        if (strstr(line, argv[1]) != NULL)
            puts(line);
    }
    if (fclose(fp) != 0)
    {
        fprintf(stderr, "File %s cannot be closed.\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    puts("Done.");
    return 0;
}

char * getLine(FILE * fp, char buff[])
{
    char * pc;
    pc = fgets(buff, MAX, fp);
    if (pc != NULL)
    {
        char * found = pc;
        while (*found != '\0')
            if (*found == '\n')
            {
                *found = '\0';
                break;
            }
            else
                found++;
    }
    return pc;
}