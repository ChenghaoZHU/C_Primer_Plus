#include <stdio.h>

int critic(void);

int main(void)
{
    printf("How many pounds to a firkin of butter?\n");
    while (critic() != 56)
        printf("No luck, my friend. Try again.\n");
    printf("You must have looked it up!\n");
    return 0;
}

int critic(void)
{
    int units;
    scanf("%d", &units);
    while (getchar() != '\n')
        continue;
    return units;
}