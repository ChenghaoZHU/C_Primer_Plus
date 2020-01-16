#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LINE_DELIMITER "******************************************\n"

void print_a(FILE *, FILE *);
void print_b(FILE *, FILE *);
int print_line(FILE *);

int main(int argc, char * argv [])
{
    FILE * f1, * f2;
    if (argc < 3)
    {
        fprintf(stderr, "Missing arguments.\n");
        exit(EXIT_FAILURE);
    }
    if ((f1 = fopen(argv[1], "r")) == NULL || (f2 = fopen(argv[2], "r")) == NULL)
    {
        fprintf(stderr, "Files cannot be opened.\n");
        exit(EXIT_FAILURE);
    }
    print_a(f1, f2);
    printf(LINE_DELIMITER);
    rewind(f1);
    rewind(f2);
    print_b(f1, f2);
    if (ferror(f1) != 0 || ferror(f2) != 0)
    {
        fprintf(stderr, "IO errors.\n");
    }
    if (fclose(f1) != 0 || fclose(f2) != 0)
    {
        fprintf(stderr, "Files cannot be closed.\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}

void print_a(FILE * f1, FILE * f2)
{
    // 交替打印文件的每一行
    int eof1, eof2;
    do
    {
        if ((eof1 = print_line(f1)) != EOF)
            putchar('\n');
        if ((eof2 = print_line(f2)) != EOF)
            putchar('\n');
    }
    while (eof1 != EOF || eof2 != EOF);
}

void print_b(FILE * f1, FILE * f2)
{
    // 行号相同的，打印成一行
    int eof1, eof2;
    do
    {
        eof1 = print_line(f1);
        eof2 = print_line(f2);
        putchar('\n');
    }
    while (eof1 != EOF || eof2 != EOF);
}

int print_line(FILE * fp)
{
    int ch;
    ch = getc(fp);
    while (ch != '\n' && ch != EOF)
    {
        putchar(ch);
        ch = getc(fp);
    }
    return ch;
}