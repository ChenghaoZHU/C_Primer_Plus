#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    char ch;
    bool in_ei = false;
    int ei_occurences = 0;
    printf("Enter some text(# to quit)\n");
    while ((ch = getchar()) != '#')
    {
        if (in_ei)
        {
            if (ch == 'i')
                ei_occurences++;
            else if (ch != 'e')
                in_ei = false;
        }
        else 
        {
            if (ch == 'e')
                in_ei = true;
        }
    }
    printf("There are %d ocurrcences of ei!\n", ei_occurences);

    return 0;
}