#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[50];
    char phone[15];
    char email[50];
} Contact;

int find_by_name(int n1, Contact list[n1], int n2, char names[n2][50])
{
    int count = 0;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (strstr(list[i].name, names[j]) != NULL)
            {
                count++;
                break;
            }
        }
    }
    return count;
}

int main()
{
    Contact list[30] = {
        {"joanna smith", "123-456-7890", "joanna@example.com"},
        {"john doe", "234-567-8901", "john@example.com"},
        {"mike johnson", "345-678-9012", "mike@example.com"},
        {"leonor white", "456-789-0123", "leonor@example.com"},
        {"caroline black", "567-890-1234", "caroline@example.com"},
    };

    char names[5][50] = {"joanna", "john", "mike", "leonor", "caroline"};
    int count = find_by_name(30, list, 5, names);

    printf("Number of contacts with at least one of the names: %d\n", count);

    return 0;
}