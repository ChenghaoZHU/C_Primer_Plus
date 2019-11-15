#include <stdio.h>

#define INCH2FOOT 12  // 12 inches = 1 foot

int main(void)
{
    char name[50];
    float height;

    printf("Enter your height and name: ");
    scanf("%f %s", &height, name);

    printf("%s, you are %.3f feet tall.\n", name, height / INCH2FOOT);

    return 0;
}