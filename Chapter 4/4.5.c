#include <stdio.h>

#define BYTE2BIT 8  // 1 Byte = 8 bits

int main(void)
{
    float downloadRate, fileSize;
    printf("Enter rate and file size: ");
    scanf("%f %f", &downloadRate, &fileSize);

    printf("At %.2f megabits per second, a file of %.2f megabytes\n", downloadRate, fileSize);
    printf("downloads in %.2f seconds.\n", fileSize *  BYTE2BIT / downloadRate);

    return 0;
}