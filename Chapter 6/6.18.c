#include <stdio.h>

int main(void)
{
    const int dunbarNum = 150;
    int weeks = 0, friends = 5;
    while (friends <= dunbarNum) {
        weeks++;
        friends -= weeks;
        friends *= 2;
        printf("Week %d, Dr. Rabund has %d friends.\n", weeks, friends);
    }
    printf("His friends have exceeded Dunbar Number.\n");
    return 0;
}