#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define SIZE 200

char * get_line(char *);

int main(void)
{
    char line[SIZE];
    int i;
    bool in_word = false;
    int word_cnt, upp_cnt, low_cnt, punc_cnt, num_cnt;
    word_cnt = upp_cnt = low_cnt = punc_cnt = num_cnt = 0;
    puts("Enter some text, ^D to quit.");
    while (get_line(line))
    {
        i = 0;
        while (line[i])
        {
            if (isalpha(line[i]))
            {
                if (!in_word)
                    in_word = true;
                if (isupper(line[i]))
                    upp_cnt++;
                else
                    low_cnt++;
            }
            else if (isdigit(line[i]))
            {
                if (in_word)
                    word_cnt++;
                in_word = false;
                num_cnt++;
            }
            else if (ispunct(line[i]))
            {
                if (in_word)
                    word_cnt++;
                in_word = false;
                punc_cnt++;
            }
            else
            {
                if (in_word)
                    word_cnt++;
                in_word = false;
            }
            i++;
        }
        if (in_word)
            word_cnt++;
    }
    printf("%-15s %-15s %-15s %-15s %-15s\n", 
           "word count", "upper count", "lower count", "punctuation count", "digit count");
    printf("%-15d %-15d %-15d %-15d %-15d\n", word_cnt, upp_cnt, low_cnt, punc_cnt, num_cnt);
    puts("Done.");
    return 0;
}

char * get_line(char * line)
{
    int i = 0;
    char * l = fgets(line, SIZE, stdin);
    if (l)
    {
        while (line[i] && line[i] != '\n')
            i++;
        if (line[i] == '\n')
            line[i] = '\0';
    }
    return l;
}