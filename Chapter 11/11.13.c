#include <stdio.h>

int main(int argc, char * argv [])
{
    int i = argc;
    if (argc < 2)
        return 0;

    while (i > 0)
        printf("%s ", argv[i--]);
    printf("\n");
    return 0;
}