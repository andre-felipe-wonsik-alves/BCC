#include <stdio.h>

typedef struct
{
    char name[50];
    float salary;
} Employee;

void print_best3(int n, Employee v[n])
{
    if (n < 3)
    {
        printf("Não há funcionários suficientes para determinar os 3 maiores salários.\n");
        return;
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (v[i].salary < v[j].salary)
            {
                Employee temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }

    printf("Top 3 funcionários com os maiores salários:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%s\n", v[i].name);
    }
}

int main()
{
    Employee employees[] = {
        {"Alice", 5000},
        {"Bob", 7000},
        {"Charlie", 6000},
        {"David", 8000},
        {"Eve", 7500}};
    int n = sizeof(employees) / sizeof(employees[0]);

    print_best3(n, employees);

    return 0;
}