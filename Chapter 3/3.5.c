#include <stdio.h>

int main(void)
{
    int age;
    double secs_per_year = 3.156e7;

    printf("Input your age: ");
    scanf("%d", &age);
    printf("It is %e seconds.\n", age * secs_per_year);

    return 0;
}