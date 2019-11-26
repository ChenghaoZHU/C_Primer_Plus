#include <stdio.h>
#include <string.h>

int main(void)
{
    int i;
    char word[50];
    printf("Enter a word: ");
    scanf("%s", word);
    for (i = strlen(word); i >= 0; i--)
    {
        printf("%c", word[i]);
    }
    printf("\n");
    return 0;
}