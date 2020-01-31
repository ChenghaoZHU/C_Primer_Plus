#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char * s_gets(char * st, int n);
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100
void eatline(void);

struct book
{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

void show_books_orderby_title(struct book [], int);
void show_books_orderby_value(struct book [], int);

int main(void)
{
    struct book library[MAXBKS];
    int count = 0;
    int index;
    printf("Please enter the book title.\n");
    printf("Press [enter] at the start of a line to stop.\n");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL 
        && library[count].title[0] != '\0')
    {
        printf("Now enter the author.\n");
        s_gets(library[count].author, MAXAUTL);
        printf("Now enter the value.\n");
        scanf("%f", &library[count++].value);
        eatline();
        if (count < MAXBKS)
            printf("Enter the next title.\n");
    }
    if (count > 0)
    {
        printf("Here is the list of your books:\n");
        for (index = 0; index < count; index++)
        {
            struct book * b = &library[index];
            printf("%s by %s: $%.2f\n", b->title, b->author, b->value);
        }
        printf("Sorted by title: \n");
        show_books_orderby_title(library, count);
        printf("Sorted by value: \n");
        show_books_orderby_value(library, count);
    }
    else
    {
        printf("No books? Too bad.\n");
    }
    
    return 0;
}

void show_books_orderby_value(struct book library[], int bks)
{
    int temp;
    int * indexes = (int *) malloc(sizeof(int) * bks);
    if (indexes)
    {
        for (int i = 0; i < bks; i++)
            indexes[i] = i;
        for (int i = 0; i < bks - 1; i++)
        {
            int min = i;
            for (int j = i + 1; j < bks; j++)
            {
                struct book b1 = library[indexes[min]];
                struct book b2 = library[indexes[j]];
                if (b1.value > b2.value)
                    min = j;
            }
            // swap
            if (min != i)
            {
                temp = indexes[i];
                indexes[i] = indexes[min];
                indexes[min] = temp;
            }
        }
    }
    else
    {
        fprintf(stderr, "No memory can be allocated.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < bks; i++)
    {
        struct book * b = &library[indexes[i]];
        printf("%s by %s: $%.2f\n", b->title, b->author, b->value);
    }
    
    free(indexes);
}

void show_books_orderby_title(struct book library[], int bks)
{
    int temp;
    int * indexes = (int *) malloc(sizeof(int) * bks);
    if (indexes)
    {
        for (int i = 0; i < bks; i++)
            indexes[i] = i;
        for (int i = 0; i < bks - 1; i++)
        {
            int min = i;
            for (int j = i + 1; j < bks; j++)
            {
                struct book b1 = library[indexes[min]];
                struct book b2 = library[indexes[j]];
                if (strcmp(b1.title, b2.title) > 0)
                    min = j;
            }
            // swap
            if (min != i)
            {
                temp = indexes[i];
                indexes[i] = indexes[min];
                indexes[min] = temp;
            }
        }
    }
    else
    {
        fprintf(stderr, "No memory can be allocated.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < bks; i++)
    {
        struct book * b = &library[indexes[i]];
        printf("%s by %s: $%.2f\n", b->title, b->author, b->value);
    }
    
    free(indexes);
}

void eatline(void)
{
    while (getchar() != '\n')
        continue; 
}

char * s_gets(char * st, int n)
{
    char * ret_val, * found;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        found = strchr(ret_val, '\n');
        if (found)
            *found = '\0';
        else
            eatline();
    }
    return ret_val;
}