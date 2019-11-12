#include <stdio.h>

int main(void)
{
    int i = 2147483647;
    float f1 = 3.4e38f, f2 = -0.1234e-38f;

    printf("Integer %d overflow is %d\n", i, i + 1);
    printf("Float %e overflow is %e\n", f1, f1 * 100);
    printf("Float %e underflow is %e\n", f2, f2 / 10000);
    
    return 0;
}