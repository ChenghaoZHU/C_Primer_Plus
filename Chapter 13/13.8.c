#include <stdio.h>
#include <stdlib.h>

int character_count_in_file(const int, FILE *);

int main(int argc, char * argv [])
{
    int ch;
    FILE * fp;
    if (argc < 2)
    {
        fprintf(stderr, "Missing arguments.\n");
        exit(EXIT_FAILURE);
    }
    ch = *argv[1];
    if (argc == 2)
    {
        puts("Enter your text in the screen: ");
        printf("In standard input %d %c occurs.\n", character_count_in_file(ch, stdin), ch);
    }
    else
    {
        for (int i = 2; i < argc; i++)
        {
            if ((fp = fopen(argv[i], "r")) == NULL)
            {
               fprintf(stderr, "File %s cannot be opened.\n", argv[i]); 
               continue;
            }
            printf("In file %s %d %c occurs.\n", argv[i], character_count_in_file(ch, fp), ch);
            if (ferror(fp) != 0)
                fprintf(stderr, "File %s has IO errors.\n", argv[i]); 
            if (fclose(fp) != 0)
                fprintf(stderr, "File %s cannot be closed.\n", argv[i]); 
        }
    }
    
    return 0;
}

int character_count_in_file(const int ch, FILE * fp)
{
    unsigned long int count = 0;
    int temp;
    while ((temp = getc(fp)) != EOF)
    {
        if (temp == ch)
            count++;
    }
    return count;
}