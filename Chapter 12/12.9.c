#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 1000
void split_words(char * [], const char [], int);
void display(char * const[], int);
void free_mem(char * [], int);
void get_line(char [], int);

int main(void)
{
    int n_words;
    char ** words;
    char * pc;
    char temp[SIZE];
    printf("How many words do you wish to enter? ");
    scanf("%d", &n_words);
    while (getchar() != '\n')
        continue;
    if (n_words > 0)
    {
        words = (char **) malloc(n_words * sizeof(char *));
        printf("Enter %d words now: \n", n_words);
        get_line(temp, SIZE);
        split_words(words, temp, n_words);
        display(words, n_words);
        free_mem(words, n_words);
    }
    puts("Done.");
    return 0;
}

void get_line(char line[], int n)
{
    int i = 0;
    fgets(line, n, stdin);
    while (i < n && line[i] != '\n')
        i++;
    if (line[i] == '\n')
        line[i] = '\0';
}

void free_mem(char * words[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (words[i])
            free(words[i]);
    }
    free(words);
}

void display(char * const words[], int n)
{
    puts("Here are your words:");
    for (int i = 0; i < n; i++)
    {
        if (words[i])
            printf("%s\n", words[i]);
    }
}

void split_words(char * words[], const char input[], int n)
{
    int i = 0;
    int s = 0, e = 0;
    int size = strlen(input);
    while (s < size && input[s] == ' ')
        s++;
    e = s;
    while (i < n)
    {
        if (s >= size)
            break;
        while (e < size && input[e] != ' ')
            e++;
        int len = e - s + 1;
        words[i] = (char *) malloc(len * sizeof(char));
        strncpy(words[i++], &input[s], len);
        s = ++e;
    }
    for (int j = i; j < n; j++)
        words[j] = NULL;
}