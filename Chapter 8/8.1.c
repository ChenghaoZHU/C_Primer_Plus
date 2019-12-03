#include <stdio.h>

int main(void)
{
    int char_cnt = 0;
    while (getchar() != EOF) 
    {
        char_cnt ++;
    }
    printf("This file has %d characters.\n", char_cnt);
    return 0;
}