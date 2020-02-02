#include <stdio.h>
#define NAMELEN 50
#define FOLKNUM 5
#define FMT1 "%s, %s, %c. -- %u\n"
#define FMT2 "%s, %s -- %u\n"

struct Name
{
    char first_name[NAMELEN];
    char middle_name[NAMELEN];
    char last_name[NAMELEN];
};

struct Person
{
    unsigned int insurance_id;
    struct Name name;
};

void print_info(struct Person[], int);
void print_info_p(struct Person *, int);

int main(void)
{
    struct Person folks[FOLKNUM] = {
        {302039823, {"Dribble", "Miler", "Flossie"}},
        {302039824, {"Kobe", "", "Bryant"}},
        {302039825, {"Bert", "Joker", "Smith"}},
        {302039826, {"Angelina", "", "Taylor"}},
        {302039827, {"Audrey", "", "Roberts"}}
    };
    print_info(folks, FOLKNUM);
    puts("--------------------------------");
    print_info_p(&folks[0], FOLKNUM);
    
    return 0;
}

void print_info_p(struct Person * folks, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (folks[i].name.middle_name[0] != '\0')
        {
            printf(FMT1, folks[i].name.first_name, folks[i].name.last_name,
                folks[i].name.middle_name[0], folks[i].insurance_id);
        }
        else
        {
            printf(FMT2, folks[i].name.first_name,
                folks[i].name.last_name, folks[i].insurance_id);
        }
    }
}

void print_info(struct Person folks[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (folks[i].name.middle_name[0] != '\0')
        {
            printf(FMT1, folks[i].name.first_name, folks[i].name.last_name,
                folks[i].name.middle_name[0], folks[i].insurance_id);
        }
        else
        {
            printf(FMT2, folks[i].name.first_name,
                folks[i].name.last_name, folks[i].insurance_id);
        }
    }
}