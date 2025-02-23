#include <stdio.h>

typedef struct
{
    char name[50];
    char phone[15];
    int type;
} Contact;

void print_contact(Contact c, int n, char type_names[n][50])
{
    if (c.type >= 0 && c.type < n)
    {
        printf("Nome: %s\n", c.name);
        printf("Telefone: %s\n", c.phone);
        printf("Tipo: %s\n", type_names[c.type]);
    }
    else
    {
        printf("Nome: %s\n", c.name);
        printf("Telefone: %s\n", c.phone);
        printf("Tipo: Desconhecido\n");
    }
}

int main()
{
    char type_names[3][50] = {"Família", "Amigo", "Trabalho"};
    Contact c = {"João Silva", "123-456-7890", 1};

    print_contact(c, 3, type_names);

    return 0;
}