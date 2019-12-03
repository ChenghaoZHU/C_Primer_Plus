#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void)
{
    int ch;
    bool in_word = false;
    int letters = 0, words = 0;  // 字母数，单词数
    while ((ch = getchar()) != EOF)
    {
        if (in_word)  // 字母连续
        {
            if (ch == ' ' || ispunct(ch) || ch == '\n')
            {
                words++;
                in_word = false;
                continue;
            }
            letters++;
        }
        else
        {
            if (ch == ' ' || ispunct(ch) || ch == '\n')
            {
                continue;
            }
            letters++;
            in_word = true;
        }
    }
    // 不考虑没有标点符号就^D结束
    if (words == 0)
        printf("No words entered.\n");
    else
        printf("There are %d words with average length %.2f letters.\n", words, (float)letters / words);
    
    return 0;
}