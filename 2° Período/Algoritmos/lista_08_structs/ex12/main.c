#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef enum
{
    AMIGO,
    TRABALHO,
    FAMILIA,
    CONHECIDO,
    OUTRO
} ContactType;

typedef struct
{
    int id;
    char name[50];
    ContactType type;
} Contact;

void fill_contact_list(int n, Contact list[n])
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        list[i].id = i + 1;
        if (strstr(list[i].name, "Doe") != NULL)
        {
            list[i].type = AMIGO;
        }
        else
        {
            list[i].type = rand() % 5;
        }
    }
}

int main()
{
    Contact list[15] = {
        {0, "John Doe", 0},
        {0, "Jane Doe", 0},
        {0, "Alice Smith", 0},
        {0, "Bob Johnson", 0},
        {0, "Charlie Brown", 0},
        {0, "David Wilson", 0},
        {0, "Eve Davis", 0},
        {0, "Frank Miller", 0},
        {0, "Grace Lee", 0},
        {0, "Hank Moore", 0},
        {0, "Ivy Taylor", 0},
        {0, "Jack Anderson", 0},
        {0, "Karen Thomas", 0},
        {0, "Leo White", 0},
        {0, "Mia Harris", 0}};

    fill_contact_list(15, list);

    for (int i = 0; i < 15; i++)
    {
        printf("ID: %d, Name: %s, Type: %d\n", list[i].id, list[i].name, list[i].type);
    }

    return 0;
}