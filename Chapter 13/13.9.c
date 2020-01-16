#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 41

int main(void)
{
    FILE * fp;
    char words[MAX];
    if ((fp = fopen("wordy", "a+")) == NULL)
    {
        fprintf(stderr, "Can't open \"wordy\" file.\n");
        exit(EXIT_FAILURE);
    }
    rewind(fp);
    puts("Enter words to add to the file; press the #");
    puts("key at the beginning of a line to terminate.");
    int i = 0;
    while (fscanf(fp, "%d", &i) == 1)
        while (getc(fp) != '\n')
            continue;
    i++;
    while ((scanf("%40s", words)) == 1 && words[0] != '#')
        fprintf(fp, "%d %s\n", i++, words);
    
    puts("File contents: ");
    rewind(fp);
    while ((fscanf(fp, "%d %s", &i, words)) == 2)
        printf("%d %s\n", i, words);
    puts("Done.");
    if (fclose(fp) != 0)
        fprintf(stderr, "Error closing file\n");
    return 0;
}