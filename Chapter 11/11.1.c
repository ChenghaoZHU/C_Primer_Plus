#include <stdio.h>
#define N 21

void get_str(char [], int);

int main(void)
{
    char strarr [N];
    printf("Enter %d characters: \n", N - 1);
    get_str(strarr, N);
    fputs(strarr, stdout);

    return 0;
}

void get_str(char str [], int len)
{
    int i = 0;
    while (i < len && (str[i++] = getchar()))
        continue;
    str[--i] = '\0';
}