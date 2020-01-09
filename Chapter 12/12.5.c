#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100
#define LB 1
#define UB 10

int rand_int(void);
void sort_int_des(int [], int);

int main(void)
{
    
    int i;
    int nums[N];
    srand((unsigned)time(NULL));
    for (i = 0; i < N; i++)
    {
        nums[i] = rand_int();
    }
    
    sort_int_des(nums, N);

    for (i = 0; i < N; i++)
    {
        printf("%d ", nums[i]);
        if (i % (N / 10) == 0)
            puts("");
    }
    printf("\n");

    return 0;
}

void sort_int_des(int nums[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (nums[i] < nums[j])
            {
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
}

int rand_int(void)
{
    return rand() % UB + LB;
}