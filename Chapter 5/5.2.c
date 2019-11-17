#include <stdio.h>

int main(void)
{
    const int length = 10;
    int i = -1;
    int n;

    printf("Enter your integer: ");
    scanf("%d", &n);
    while (i++ < length)
    {
        printf("%d ", n + i);
    }
    printf("\n");
    
    return 0;
}