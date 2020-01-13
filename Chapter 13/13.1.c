#include <stdio.h>
#include <stdlib.h>  // 提供exit()的原型
#define SLEN 81
char * get_file_name(char *, int);

int main(void)
{
    char fname[SLEN];
    char * file_name;
    int ch;
    unsigned long int count = 0;
    FILE *fp;
    printf("Enter file name to open: ");
    file_name = get_file_name(fname, SLEN);
    if ((fp = fopen(file_name, "r")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", file_name);
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(fp)) != EOF)
    {
        putc(ch, stdout);
        count++;
    }
    if (fclose(fp) != 0)
    {
        fprintf(stderr, "Can't close %s\n", file_name);
        exit(EXIT_FAILURE);
    }
    printf("\nFile %s has %lu characters\n", file_name, count);
    
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