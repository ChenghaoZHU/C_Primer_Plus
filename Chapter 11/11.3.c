#include <stdio.h>
#define LEN 20
#define HALT 'q'

void get_word(char []);

int main(void)
{
    char word[LEN];
    printf("Enter a line: \n");
    get_word(word);
    while (word[0] != HALT || word[1] != '\0')
    {
        puts(word);
        printf("Enter a line again('%c' to quit): \n", HALT);
        get_word(word);
    }
    puts("Bye.");
    
    return 0;
}

void get_word(char word [])
{
    scanf("%s", word);
    while (getchar() != '\n')
        continue;
}