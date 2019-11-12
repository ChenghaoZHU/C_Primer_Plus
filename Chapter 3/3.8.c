#include <stdio.h>

int main(void)
{
    int cup_num;
    float pint2cup = 2L;
    float cup2ounce = 8L;
    float ounce2laddle = 2L;
    float laddle2spoon = 3L;

    printf("Input cup num: ");
    scanf("%d", &cup_num);
    printf("it's %f pints\n", cup_num / pint2cup);
    printf("it's %f ounces\n", cup_num * cup2ounce);
    printf("it's %f laddles\n", cup_num * cup2ounce * ounce2laddle);
    printf("it's %f spoons\n", cup_num * cup2ounce * ounce2laddle * laddle2spoon);
    
    return 0;
}