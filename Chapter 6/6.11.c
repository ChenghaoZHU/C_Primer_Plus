#include <stdio.h>
#define SIZE 8

int main(void)
{
    int nums[SIZE];
    int i;

    printf("Enter %d integers: ", SIZE);
    for (i = 0; i < SIZE; i++)
    {
        scanf("%d", &nums[i]);
    }
    printf("The numbers are: ");
    
    for (i = 0; i < SIZE; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");

    printf("Here they are reversed: ");
    for (i = SIZE - 1; i >= 0; i--)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}