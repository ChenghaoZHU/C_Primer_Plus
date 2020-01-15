#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 4096

void append(FILE *, FILE *);

int main(int argc, char * argv[])
{
    FILE * src, * des;
    if (argc < 3)
    {
        fputs("Usage: ./13.5.out source destination\n", stderr);
        exit(EXIT_FAILURE);
    }
    if ((src = fopen(argv[1], "r")) == NULL || (des = fopen(argv[2], "a")) == NULL)
    {
        fputs("File can be opened.\n", stderr);
        exit(EXIT_FAILURE);
    }
    if (setvbuf(src, NULL, _IOFBF, BUFSIZE) != 0 || setvbuf(des, NULL, _IOFBF, BUFSIZE) != 0)
    {
        fputs("No spaces for buffer.\n", stderr);
        exit(EXIT_FAILURE);
    }
    append(src, des);
    if (ferror(src) != 0 || ferror(des) != 0)
    {
        fputs("ERROR in file IO.\n", stderr);
    }
    if (fclose(src) != 0 || fclose(des) != 0)
    {
        fputs("Can't close files.\n", stderr);
        exit(EXIT_FAILURE);
    }
    printf("Done.\n");
    return 0;
}

void append(FILE * src, FILE * des)
{
    size_t bytes;
    static char temp[BUFSIZE];

    while ((bytes = fread(temp, sizeof(char), BUFSIZE, src)) > 0)
        fwrite(temp, sizeof(char), bytes, des);
}