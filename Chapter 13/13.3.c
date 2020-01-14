#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define SIZE 81

char * get_file_name(char *, int);

int main(void)
{
    char file_path[SIZE], * fn;
    int ch;
    unsigned long i = 0;
    FILE * fp;
    printf("Enter file path: ");
    fn = get_file_name(file_path, SIZE);
    if (fn)
    {
        if ((fp = fopen(fn, "r+")) == NULL)
        {
            fprintf(stderr, "File %s cannot be opened for IO.\n", fn);
            exit(EXIT_FAILURE);
        }
        while ((ch = getc(fp)) != EOF)
        {
           fseek(fp, sizeof(char) * i, SEEK_SET);
           putc(toupper(ch), fp);
           i++;
        }
        if (ferror(fp) != 0)
        {
            fprintf(stderr, "IO Error for file %s\n", fn);
        }
        if (fclose(fp) != 0)
        {
            fputs("Cannot close files\n", stderr);
            exit(EXIT_FAILURE);
        }
    }
    printf("Done.\n");
    return 0;
}

char * get_file_name(char * fname, int n)
{
    char * file_name;
    char * l_pos;
    file_name = fgets(fname, n, stdin);
    if (file_name)
    {
        l_pos = file_name;
        while (*l_pos != '\0' && *l_pos != '\n')
            l_pos++;
        if (*l_pos)
            *l_pos = '\0';
        else
        {
            while (getchar()  != '\n')
                continue;           
        }
    }
    return file_name;
}