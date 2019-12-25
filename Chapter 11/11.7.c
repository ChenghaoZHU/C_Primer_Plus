#include <stdio.h>
#define SIZE 50
char * mystrncpy(char *, const char *, int);

int main(void)
{
    int n, i;
    char tgt[SIZE], src[SIZE];
    puts("Enter an integer and two strings(length, target, source): ");
    while (scanf("%d %s %s", &n, tgt, src) == 3)
    {
        printf("target: %s\n", tgt);
        printf("source: %s\n", src);
        printf("length: %d\n", n);
        mystrncpy(tgt, src, n);
        i = 0;
        while (i < n)
        {
            if(tgt[i] == '\0')
                break;
            putchar(tgt[i]);
            i++;
        }
        puts("\nEnter an integer and two strings(length, target, source), non-numeric to quit: ");
    }
    puts("Bye.");
    return 0;
}

char * mystrncpy(char * target, const char * source, int length)
{
    int i = 0;
    while (i < length && source[i] != '\0')
    {
        target[i] = source[i];
        i++;
    }
    if (i != length)
    {
        target[i] = '\0';
    }
    return target;
}