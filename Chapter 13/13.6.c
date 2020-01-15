#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 40

char * get_file_name(char *, int);

int main(void)
{
    FILE * in, * out;
    int ch;
    char name[LEN], name_red[LEN + 4], * pn;
    int count = 0;

    printf("Enter file name: ");
    if ((pn = get_file_name(name, LEN)) != NULL)
    {
        strncpy(name_red, pn, LEN);
        strcat(name_red, ".red");
        if ((in = fopen(pn, "r")) == NULL || (out = fopen(name_red, "w")) == NULL)
        {
            fprintf(stderr, "Can't open files.\n");
            exit(EXIT_FAILURE);
        }
        while ((ch = getc(in)) != EOF)
        {
            if (count++ % 3 == 0)
                putc(ch, out);
        }
        if (fclose(in) != 0 || fclose(out) != 0)
        {
            fprintf(stderr, "Can't close files.\n");
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