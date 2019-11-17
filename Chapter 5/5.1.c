#include <stdio.h>

#define MIN_PER_HOUR 60

int main(void)
{
    int mins;
    printf("Enter minites(0 to quit): ");
    scanf("%d", &mins);
    
    while (mins > 0)
    {
        printf("%d minutes is %d hours and %d minutes.\n", mins, mins / MIN_PER_HOUR, mins % MIN_PER_HOUR);
        printf("Enter minites(0 to quit): ");
        scanf("%d", &mins);
    }
    
    return 0;
}