#include <stdio.h>
#include <string.h>
#define LEN 20
#define LMT 11
#define HALT 'q'

void get_word(char [], int);

int main(void)
{
    char word[LEN];
    printf("Enter a line: \n");
    get_word(word, LMT);
    while (word[0] != HALT || word[1] != '\0')
    {
        puts(word);
        printf("Enter a line again('%c' to quit): \n", HALT);
        get_word(word, LMT);
    }
    puts("Bye.");
    
    return 0;
}

void get_word(char word [], int lmt)
{
    scanf("%s", word);
    if (strlen(word) > lmt)
        word[lmt] = '\0';
    while (getchar() != '\n')
        continue;
}