#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define SEATN 12
#define STRN 50
#define FLIGHTN 4

struct seat {
    short seat_no;
    bool reserved;
    char first_name[STRN];
    char last_name[STRN];
};
typedef struct seat Seat;

struct flight {
    short flight_no;
    Seat seats[SEATN];
    int seat_count;
};
typedef struct flight Flight;

Flight flights[FLIGHTN];  // 四架航班

void init();
void show_menu(void);
char get_option(void);
void eatline(void);
char * s_gets(char * st, int n);
void show_empty_seat_num(int);
void show_empty_seats(int);
void show_alpha_seats(int);
void set_seat(int);
void reset_seat(int);
void book_seats(int);
void _set_seat(int n, int i);

int main(void)
{
    init();
    int flight_no;
    printf("Enter flight number (q to quit): ");
    while (scanf("%d", &flight_no) == 1)
    {
        eatline();
        book_seats(flight_no);
        printf("Enter flight number (q to quit): ");
    }
    eatline();
    puts("Bye.");
    return 0;
}

void book_seats(int flight_no)
{
    int index = -1;
    for (int i = 0; i < FLIGHTN; i++)
    {
        if (flights[i].flight_no == flight_no)
        {
            index = i;
            break;
        }        
    }
    if (index == -1)
    {
        printf("Flight %d does not exist.\n", flight_no);
        return ;
    }
    int op;
    while ((op = get_option()) != EOF && op != 'f')
    {
        switch (op)
        {
            case 'a': show_empty_seat_num(index); break;
            case 'b': show_empty_seats(index); break;
            case 'c': show_alpha_seats(index); break;
            case 'd': set_seat(index); break;
            case 'e': reset_seat(index); break;
            default: puts("Invalid option"); break;
        }
    }
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

void _set_seat(int n, int i)
{
    printf("Enter first name: ");
    s_gets(flights[n].seats[i].first_name, STRN);
    printf("Enter last name: ");
    s_gets(flights[n].seats[i].last_name, STRN);
    flights[n].seats[i].reserved = true;
    flights[n].seat_count++;
}

void reset_seat(int n)
{
    int flight_no = flights[n].flight_no;
    int i;
    printf("Which seat do you want to delete in Flight %d?\n", flight_no);
    while (scanf("%d", &i) == 1)
    {
        eatline();
        if (i < 0 || i >= SEATN)
            printf("Invalid num, please enter a num between 0 and %d", SEATN - 1);
        if (flights[n].seats[i].reserved)
        {
            flights[n].seats[i].reserved = false;
            flights[n].seat_count--;
        }
        printf("Which seat do you want to delete in Flight %d?\n", flight_no);
    }
    eatline();
}

void set_seat(int n)
{
    int flight_no = flights[n].flight_no;
    int i;
    printf("Which seat do you want to set in Flight %d?\n", flight_no);
    while (scanf("%d", &i) == 1)
    {
        eatline();
        if (i < 0 || i >= SEATN)
            printf("Invalid num, please enter a num between 0 and %d\n", SEATN - 1);
        else if (flights[n].seats[i].reserved)
            printf("Seat %d is not available.\nTry again.\n", i);
        else
            _set_seat(n, i);
        printf("Which seat do you want to set in Flight %d?\n", flight_no);
    }
    eatline();
}

void show_alpha_seats(int no)
{
    int seat_count = flights[no].seat_count;
    int * buff = (int *) malloc(seat_count * sizeof(int));
    int index = 0;
    for (int i = 0; i < SEATN; i++)
    {
        if (flights[no].seats[i].reserved)
            buff[index++] = i;
    }
    for (int i = 0; i < index - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < index; j++)
        {
            if (strcmp(flights[no].seats[buff[j]].first_name, flights[no].seats[buff[min]].first_name) < 0)
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
        printf("%s %s booked seat %d in Flight %d\n", flights[no].seats[j].first_name,
            flights[no].seats[j].last_name, flights[no].seats[j].seat_no,
            flights[no].flight_no);
    }
    free(buff);
}

void show_empty_seats(int no)
{
    int flight_no = flights[no].flight_no;
    printf("The empty seats in Flight %d are: ", flight_no);
    for (int i = 0; i < SEATN; i++)
    {
        if (!flights[no].seats[i].reserved)
            printf("%d ", flights[no].seats[i].seat_no);
    }
    putchar('\n');
}

void show_empty_seat_num(int i)
{
    int num = SEATN - flights[i].seat_count;
    int flight_no = flights[i].flight_no;
    if (num)
        printf("There are still %d empty seats in Flight %d.\n", num, flight_no);
    else
        printf("No seats available in Flight %d.\n", flight_no);
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

void init()
{
    flights[0].flight_no = 102;
    flights[1].flight_no = 311;
    flights[2].flight_no = 444;
    flights[3].flight_no = 519;
    for (int i = 0; i < FLIGHTN; i++)
    {
        for (int j = 0; j < SEATN; j++)
        {
            flights[i].seats[j].reserved = false;
            flights[i].seats[j].seat_no = j;
        }
        flights[i].seat_count = 0;
    }
}