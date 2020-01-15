#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "No files specified.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 1; i < argc; i++)
        printf("%d: %s\n", i, argv[i]);
    puts("Done.");
    return 0;
}