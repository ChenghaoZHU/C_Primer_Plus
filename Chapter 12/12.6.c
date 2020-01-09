#include <stdio.h>
#include <stdlib.h>

#define N 1000
#define LB 1
#define UB 10

int rand_int(void);

int main(void)
{
    int seed, i;
    int size = UB - LB + 2;
    int counter[size];
    for (i = 1; i < size; i++)
        counter[i] = 0;
    puts("Enter seed: ");
    scanf("%d", &seed);
    srand(seed);
    for (i = 0; i < N; i++)
        counter[rand_int()]++;
    
    for (i = 1; i < size; i++)
        printf("%d occurs %d times.\n", i, counter[i]);

    return 0;
}

int rand_int(void)
{
    return rand() % UB + LB;
}