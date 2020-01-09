#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LINELIMIT 15

int roll_n_dice(int, int);

int main(void)
{
    srand((unsigned)time(NULL));
    int sets, i;
    printf("Enter the number of sets; enter q to stop : ");
    while (scanf("%d", &sets) == 1 && sets > 0)
    {
        int sides, dice;
        printf("How many sides and how many dice? ");
        scanf("%d %d", &sides, &dice);
        printf("Here are %d sets of %d %d-sided throws.\n", sets, dice, sides);
        for (i = 0; i < sets;)
        {   
            i++;
            printf("%d ", roll_n_dice(dice, sides));
            if (i % LINELIMIT == 0)
                putchar('\n');
        }
        if (i % LINELIMIT)
            putchar('\n');
        printf("Enter the number of sets; enter q to stop : ");
    }
    puts("Bye.");
    return 0;
}

int roll_n_dice(int dice, int sides)
{
    int points = 0;
    for (int i = 0; i < dice; i++)
    {
        points += rand() % sides + 1;
    }
    return points;
}