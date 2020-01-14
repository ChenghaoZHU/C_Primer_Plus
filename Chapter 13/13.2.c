#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFSIZE 4096
void copy(FILE *, FILE *);

int main(int argc, char * argv[])
{
    FILE * out, * in;
    char * src, * tgt;
    if (argc < 3)
    {
        fprintf(stderr, "Usage: 13.2.out src tgt\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        src = argv[1];
        tgt = argv[2];
    }
    if (strcmp(src, tgt) == 0)
    {
        fprintf(stderr, "Target file cannot has the same name with source file - %s\n", src);
        exit(EXIT_FAILURE);
    }

    if ((out = fopen(src, "rb")) == NULL)
    {
        fprintf(stderr, "Source file %s can't be opened.\n", src);
        exit(EXIT_FAILURE);
    }
    else if ((in = fopen(tgt, "wb")) == NULL)
    {
        fprintf(stderr, "Target file %s can't be opened.\n", tgt);
        exit(EXIT_FAILURE);
    }

    if (setvbuf(out, NULL, _IOFBF, BUFFSIZE) != 0)
    {
        fputs("Can't create output buffer\n", stderr);
        exit(EXIT_FAILURE);
    }
    else if (setvbuf(in, NULL, _IOFBF, BUFFSIZE) != 0)
    {
        fputs("Can't create input buffer\n", stderr);
        exit(EXIT_FAILURE);
    }
    
    copy(out, in);
    if (ferror(out) != 0)
    {
        fprintf(stderr, "Error in reading file %s\n", src);
    }
    else if (ferror(in) != 0)
    {
        fprintf(stderr, "Error in writing file %s\n", tgt);
    }
    

    if (fclose(out) != 0 || fclose(in) != 0)
    {
        fputs("Cannot close files\n", stderr);
        exit(EXIT_FAILURE);
    }

    return 0;
}

void copy(FILE * out, FILE * in)
{
    size_t bytes;
    static char buff[BUFFSIZE];
    while ((bytes = fread(buff, sizeof(char), BUFFSIZE, out)) > 0)
    {
        fwrite(buff, sizeof(char), bytes, in);
    }
}