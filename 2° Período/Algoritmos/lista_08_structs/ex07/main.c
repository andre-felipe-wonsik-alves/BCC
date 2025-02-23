#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[50];
    char phone[15];
    char type[50];
} Contact;

void print_contact_list(int n1, Contact list[n1], int n2, char types[n2][50])
{
    for (int i = 0; i < n2; i++)
    {
        printf("Contatos do tipo %s:\n", types[i]);
        for (int j = 0; j < n1; j++)
        {
            if (strcmp(list[j].type, types[i]) == 0)
            {
                printf("Name: %s, Phone: %s\n", list[j].name, list[j].phone);
            }
        }
        printf("\n");
    }
}

int main()
{
    Contact contacts[] = {
        {"Alice", "123-456-7890", "Amigo"},
        {"Bob", "234-567-8901", "Família"},
        {"Charlie", "345-678-9012", "Trabalho"},
        {"David", "456-789-0123", "Amigo"},
        {"Eve", "567-890-1234", "Trabalho"}};
    char types[][50] = {"Amigo", "Família", "Trabalho"};

    print_contact_list(5, contacts, 3, types);

    return 0;
}