#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define SEATN 12
#define STRN 50

int seat_count = 0;
struct seat {
    short seat_no;
    bool reserved;
    char first_name[STRN];
    char last_name[STRN];
};
typedef struct seat Seat;

Seat seats[SEATN];
void init(Seat [], int);
void show_menu(void);
char get_option(void);
void eatline(void);
char * s_gets(char * st, int n);
void show_empty_seat_num(void);
void show_empty_seats(void);
void show_alpha_seats(void);
void set_seat(void);
void reset_seat(void);

int main(void)
{
    int op;
    init(seats, SEATN);
    while ((op = get_option()) != EOF && op != 'f')
    {
        switch (op)
        {
            case 'a': show_empty_seat_num(); break;
            case 'b': show_empty_seats(); break;
            case 'c': show_alpha_seats(); break;
            case 'd': set_seat(); break;
            case 'e': reset_seat(); break;
            default: puts("Invalid option"); break;
        }
    }
    puts("Bye.");
    return 0;
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

void _set_seat(int i)
{
    printf("Enter first name: ");
    s_gets(seats[i].first_name, STRN);
    printf("Enter last name: ");
    s_gets(seats[i].last_name, STRN);
    seats[i].reserved = true;
    seat_count++;
}

void reset_seat(void)
{
    int i;
    printf("Which seat do you want to delete?\n");
    while (scanf("%d", &i) == 1)
    {
        eatline();
        if (i < 0 || i >= SEATN)
            printf("Invalid num, please enter a num between 0 and %d", SEATN - 1);
        if (seats[i].reserved)
        {
            seats[i].reserved = false;
            seat_count--;
        }
        printf("Which seat do you want to delete?\n");
    }
    eatline();
}

void set_seat(void)
{
    int i;
    printf("Which seat do you want to set?\n");
    while (scanf("%d", &i) == 1)
    {
        eatline();
        if (i < 0 || i >= SEATN)
            printf("Invalid num, please enter a num between 0 and %d\n", SEATN - 1);
        else if (seats[i].reserved)
            printf("Seat %d is not available.\nTry again.\n", i);
        else
            _set_seat(i);
        printf("Which seat do you want to set?\n");
    }
    eatline();
}

void show_alpha_seats(void)
{
    int * buff = (int *) malloc(seat_count * sizeof(int));
    int index = 0;
    for (int i = 0; i < SEATN; i++)
    {
        if (seats[i].reserved)
            buff[index++] = i;
    }
    for (int i = 0; i < index - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < index; j++)
        {
            if (strcmp(seats[buff[j]].first_name, seats[buff[min]].first_name) < 0)
                min = j;
        }
        if (i != min)
        {
            int temp;
            temp = buff[i];
            buff[i] = buff[min];
            buff[min] = temp;
        }
    }
    for (int i = 0; i < index; i++)
    {
        int j = buff[i];
        printf("%s %s booked seat %d\n", seats[j].first_name,
            seats[j].last_name, seats[j].seat_no);
    }
    free(buff);
}

void show_empty_seats(void)
{
    printf("The empty seats are: ");
    for (int i = 0; i < SEATN; i++)
    {
        if (!seats[i].reserved)
            printf("%d ", seats[i].seat_no);
    }
    putchar('\n');
}

void show_empty_seat_num(void)
{
    int num = SEATN - seat_count;
    if (num)
        printf("There are still %d empty seats.\n", num);
    else
        printf("No seats available.\n");
}

void show_menu(void)
{
    puts("To choose a function, enter its letter label: ");
    puts("a) Show number of empty seats");
    puts("b) Show list of empty seats");
    puts("c) Show alphabetical list of seats");
    puts("d) Assign a customer to a seat assignment");
    puts("e) Delete a seat assignment");
    puts("f) Quit");
}

char get_option(void)
{
    show_menu();
    char ch;
    while (scanf("%c", &ch) != 1)
        eatline();
    eatline();
    return ch;
}

void eatline(void)
{
    while (getchar() != '\n')
        continue; 
}

void init(Seat seats[], int n)
{
    for (int i = 0; i < n; i++)
    {
        seats[i].reserved = false;
        seats[i].seat_no = i;
    }
}