#include <stdio.h>
#include <string.h>
#define CHARL 50
#define GRADEL 3
#define CSIZE 4

struct name
{
    char first_name[CHARL];
    char last_name[CHARL];
};

struct student
{
    struct name s_name;
    float grade[GRADEL];
    float average;
};

void eatline(void);
char * s_gets(char *, int);
void get_grades(float [], int);
void record_grades(struct student[], int);
void cal_average_scores(struct student[], int);
void show_info(struct student[], int);
void print_average(struct student[], int);

int main(void)
{
    struct student s_students[CSIZE] = {
        {{"Jack", "Bryant"}},
        {{"Rose", "Christain"}},
        {{"Andrew", "Yu"}},
        {{"David", "Chen"}}
    };
    record_grades(s_students, CSIZE);
    cal_average_scores(s_students, CSIZE);
    show_info(s_students, CSIZE);
    print_average(s_students, CSIZE);
    puts("Bye.");
    return 0;
}

void print_average(struct student s_students[], int n)
{
    puts("Display average scores for all students.");
    float avg1, avg2;
    avg1 = avg2 = 0;
    for (int i = 0; i < n; i++)
    {
        struct student s = s_students[i];
        avg1 += s.average;
        for (int j = 0; j < GRADEL; j++)
            avg2 += s.grade[j];
    }
    avg1 /= n, avg2 /= n * GRADEL;
    printf("Total avg is %.4f, %.4f\n", avg1, avg2);
}

void show_info(struct student s_students[], int n)
{
    puts("Grade information: ");
    for (int i = 0; i < n; i++)
    {
        struct student s = s_students[i];
        printf("%s %s got ", s.s_name.first_name, s.s_name.last_name);
        for (int j = 0; j < GRADEL; j++)
            printf("%.1f ", s.grade[j]);
        printf("with avg: %.1f\n", s.average);
    }
    puts("Done.");
}

void cal_average_scores(struct student s_students[], int n)
{
    puts("Calculating averages...");
    for (int i = 0; i < n; i++)
    {
        struct student * s = &s_students[i];
        float scores = 0.0;
        for (int j = 0; j < GRADEL; j++)
        {
            scores += s->grade[j];
        }
        s->average = scores / GRADEL;
    }
    puts("Averages set up.");
}

void record_grades(struct student s_students[], int n)
{
    puts("Please enter students' grades");
    for (int i = 0; i < n; i++)
    {
        struct student * s = &s_students[i];
        printf("%s %s: ", s->s_name.first_name, s->s_name.last_name);
        get_grades(s->grade, GRADEL);
    }
    puts("Grades entered.");
}

void eatline(void)
{
    while (getchar() != '\n')
        continue;
}

void get_grades(float grades[], int n)
{
    for (int i = 0; i < n; i++)
    {
        while (scanf("%f", &grades[i]) != 1)
            eatline();
    }
    eatline();
}

char * s_gets(char * buff, int n)
{
    char * input;
    input = fgets(buff, n, stdin);
    if (input)
    {
        char * found = strchr(input, '\n');
        if (found)
            *found = '\0';
        else
            eatline();
    }
    return input;
}