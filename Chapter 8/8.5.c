#include <stdio.h>
#define MIN 0
#define MAX 100

char get_tip(void);

int main(void)
{
    char tip;
    int min = MIN, max = MAX;
    int guess = (MIN + MAX) / 2;
    printf("Pick an integer from %d to %d. I will try to guess ", MIN, MAX);
    printf("it.\nRespond with a y if my guess is right and with");
    printf("\na h if it is higher and with an l if it is lower.\n");
    printf("Un...is your number %d?\n", guess);
    while ((tip = get_tip()) != 'y')
    {
        if (tip == 'h')
        {
            max = guess;
        }
        else if (tip == 'l')
        {
            min = guess;
        }
        guess = (min + max) / 2;
        printf("Well, then, is it %d?\n", guess);
    }
    printf("I knew I could do it!\n");
    return 0;
}

char get_tip(void)
{
    char tip;
    do
    {
        tip = getchar();
        while (getchar() != '\n')
            continue;
        if (tip == 'h' || tip == 'l' || tip == 'y')
            return tip;
        else
            printf("Only h l y is valid input.\nEnter AGAIN: ");
    } while (1);
}