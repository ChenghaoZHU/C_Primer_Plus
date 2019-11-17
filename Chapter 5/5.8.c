#include <stdio.h>

int main(void)
{
    int st_op, nd_op;

    printf("This program computes moduli.\n");
    printf("Enter an integer to serve as the second oprand: ");
    scanf("%d", &nd_op);
    printf("Now enter the first operand: ");
    scanf("%d", &st_op);
    while (st_op > 0)
    {
        printf("%d %% %d is %d\n", st_op, nd_op, st_op % nd_op);
        printf("Enter next number for first operand (<=0 to quit): ");
        scanf("%d", &st_op);
    }
    printf("Done\n");
    
    return 0;
}