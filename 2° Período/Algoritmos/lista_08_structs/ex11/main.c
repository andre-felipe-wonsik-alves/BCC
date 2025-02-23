#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct
{
    int id;
    char name[100];
    char email[120];
    int type;
} Contact;

void verificar_corrigir_nome(char name[]);

Contact create_contact(int id, char name[], int type)
{
    Contact new_contact;
    new_contact.id = id;

    strcpy(new_contact.name, name);

    int i, j = 0;
    for (i = 0; name[i] != '\0'; i++)
    {
        if (name[i] == ' ')
        {
            new_contact.email[j++] = '.';
        }
        else
        {
            new_contact.email[j++] = tolower(name[i]);
        }
    }
    strcpy(new_contact.email + j, "@mail.br");

    new_contact.type = type;

    return new_contact;
}

int main()
{
    Contact contato = create_contact(1, "João da Silva", 2);
    printf("ID: %d\n", contato.id);
    printf("Nome: %s\n", contato.name);
    printf("Email: %s\n", contato.email);
    printf("Tipo: %d\n", contato.type);

    return 0;
}