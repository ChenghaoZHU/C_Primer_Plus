#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10
#define BUFF 50

char * s_gets(char * st, int n);
struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
    short is_existed;
};
void eatline(void);
int delete_or_upadte_books(struct book [], int);
int get_int(int);
int delete_books(struct book [], int);
void update_books(struct book [], int);
void show_book_list(struct book [], int);
int get_next_index(struct book [], int);

int main(void)
{
    struct book library[MAXBKS];
    int count = 0;
    int index;
    bool has_records = true;
    FILE * pbooks;
    int size = sizeof(struct book);

    if ((pbooks = fopen("book.dat", "rb")) == NULL)
        has_records = false;
    for (int i = 0; i < MAXBKS; i++)
        library[i].is_existed = 0;  // 初始化
    while (has_records && count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
    {
        if (!count)
            puts("Current contents of book.dat: ");
        printf("%s by %s: %.2f\n", library[count].title,
            library[count].author, library[count].value);
        library[count++].is_existed = 1;
    }
    fclose(pbooks);
    if (count)
        count = delete_or_upadte_books(library, count);
    if (count == MAXBKS)
    {
        fputs("The book.dat file is full.", stderr);
        exit(EXIT_FAILURE);
    }

    puts("Please add new book titles.");
    puts("Press [enter] at the start of a line to stop.");
    while (count < MAXBKS && (index = get_next_index(library, MAXBKS)) 
        && s_gets(library[index - 1].title, MAXTITL) != NULL &&
        library[index - 1].title[0] != '\0')
    {
        puts("Now enter the author.");
        s_gets(library[index - 1].author, MAXAUTL);
        puts("Now enter the value.");
        scanf("%f", &library[index - 1].value);
        library[index - 1].is_existed = 1;
        eatline();
        if (++count < MAXBKS)
            puts("Enter the next title.");
    }
    
    if (count > 0)
    {
        puts("Here is the list of your books: ");
        show_book_list(library, MAXBKS);
        if ((pbooks = fopen("book.dat", "wb")) == NULL)
        {
            fputs("Can't open book.dat file\n", stderr);
            exit(EXIT_FAILURE);
        }
        for (index = 0; index < MAXBKS; index++)
            if (library[index].is_existed)
                fwrite(&library[index], size, 1, pbooks);
        fclose(pbooks);
    }
    else
        puts("No books? Too bad.");

    puts("Bye.");
    return 0;
}

int get_next_index(struct book library[], int n)
{
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        if (!library[i].is_existed)
        {
            index = i + 1;
            break;
        }
    }
    return index;
}

void show_book_list(struct book library[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (library[i].is_existed)
            printf("%s by %s: %.2f.\n", library[i].title, library[i].author,
                library[i].value);
    }
}

void update_books(struct book library[], int i)
{
    if (library[i].is_existed)
    {
        puts("Please add new book titles.");
        s_gets(library[i].title, MAXTITL);
        puts("Now enter the author.");
        s_gets(library[i].author, MAXAUTL);
        puts("Now enter the value.");
        scanf("%f", &library[i].value);
        eatline();
    }
    else
        printf("Book %d has been deleted already.\n", i);
}

int delete_books(struct book library[], int i)
{
    if (library[i].is_existed)
    {
        library[i].is_existed = 0;
        printf("Book %d has been deleted.\n", i);
        return 1;
    }
    printf("Book %d has been deleted already.\n", i);
    return 0;
}

int delete_or_upadte_books(struct book library[], int n)
{
    char buff[BUFF], * mode;
    int count = n;
    printf("Enter edit mode(d for delete, u for update): ");
    while ((mode = s_gets(buff, 2)) != NULL && mode[0] != '\0')
    {
        if (*mode == 'd')
        {
            puts("Which one do you want to delete?");
            count -= delete_books(library, get_int(n));
        }
        else if (*mode == 'u')
        {
            puts("Which one do you want to update?");
            update_books(library, get_int(n));
        }
        else
            puts("Invalid operations!");
        printf("Enter edit mode(d for delete, u for update) - [Enter] at the start of a line to stop: ");
    }
    return count;
}

int get_int(int n)
{
    int i;
    printf("Enter 0 to %d: ", n);
    while (scanf("%d", &i) != 1 || i < 0 || i > n)
    {
        eatline();
        printf("Enter 0 to %d: ", n);
    }
    eatline();
    return i;
}

void eatline(void)
{
    while (getchar() != '\n')
        continue;
}

char * s_gets(char * st, int n)
{
    char * found, * ret_val;
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