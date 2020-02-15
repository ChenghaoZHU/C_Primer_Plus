#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 100
#define LINE "************************************************"

void transform(double [], double [], int, double (*) (double));
void display(double [], int);
double add_one(double);
double squared(double);

int main(void)
{
    srand((unsigned) time(NULL));
    double source[N], target[N];
    for (int i = 0; i < N; i++)
        source[i] = rand() % 181;
    display(source, N);
    puts(LINE);
    puts("apply to sin: ");
    transform(source, target, N, sin);
    display(target, N);
    puts(LINE);
    puts("apply to cos: ");
    transform(source, target, N, cos);
    display(target, N);
    puts(LINE);
    puts("apply to add_one: ");
    transform(source, target, N, add_one);
    display(target, N);
    puts(LINE);
    puts("apply to squared: ");
    transform(source, target, N, squared);
    display(target, N);
    
    return 0;
}

double squared(double n)
{
    return n * n;
}

double add_one(double n)
{
    return n + 1;
}

void display(double arr[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
        if (i % 10 == 0 && i != 0)
            putchar('\n');
    }
    putchar('\n');
}

void transform(double source[], double target[], int n, double (* func) (double))
{
    for (int i = 0; i < n; i++)
    {
        target[i] = func(source[i]);
    }
}