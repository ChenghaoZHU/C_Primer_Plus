#include <stdio.h>

int called(void);

int main(void)
{
    int ch;
    int i = 0;
    puts("Call function? y/n");
    while (getchar() == 'y')
    {
        while (getchar() != '\n')
            continue; 
        i = called();
        puts("Call function? y/n");
    }
    printf("The function is called for %d times.\n", i);
    return 0;
}

int called(void)
{
    static int i = 0;  // 静态存储期，块级作用域，无链接
    return ++i;
}