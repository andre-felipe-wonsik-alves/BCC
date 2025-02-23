#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[50];
    char tipo[20];
    float salario;
} Empregado;

void relatorio_rendimentos(int n, Empregado v[n])
{
    float salario_total = 0;
    float salario_total_desenvolvedor = 0;
    float salario_total_designer = 0;
    float salario_total_gerente = 0;
    float salario_total_suporte = 0;
    int contador_desenvolvedor = 0;
    int contador_designer = 0;
    int contador_gerente = 0;
    int contador_suporte = 0;

    for (int i = 0; i < n; i++)
    {
        salario_total += v[i].salario;

        if (strcmp(v[i].tipo, "Desenvolvedor") == 0)
        {
            salario_total_desenvolvedor += v[i].salario;
            contador_desenvolvedor++;
        }
        else if (strcmp(v[i].tipo, "Designer") == 0)
        {
            salario_total_designer += v[i].salario;
            contador_designer++;
        }
        else if (strcmp(v[i].tipo, "Gerente") == 0)
        {
            salario_total_gerente += v[i].salario;
            contador_gerente++;
        }
        else if (strcmp(v[i].tipo, "Suporte") == 0)
        {
            salario_total_suporte += v[i].salario;
            contador_suporte++;
        }
    }

    float salario_medio = salario_total / n;
    float salario_medio_desenvolvedor = contador_desenvolvedor ? salario_total_desenvolvedor / contador_desenvolvedor : 0;
    float salario_medio_designer = contador_designer ? salario_total_designer / contador_designer : 0;
    float salario_medio_gerente = contador_gerente ? salario_total_gerente / contador_gerente : 0;
    float salario_medio_suporte = contador_suporte ? salario_total_suporte / contador_suporte : 0;

    printf("Salário Total: %.2f\n", salario_total);
    printf("Salário Médio: %.2f\n", salario_medio);
    printf("Salário Médio de Desenvolvedor: %.2f\n", salario_medio_desenvolvedor);
    printf("Salário Médio de Designer: %.2f\n", salario_medio_designer);
    printf("Salário Médio de Gerente: %.2f\n", salario_medio_gerente);
    printf("Salário Médio de Suporte: %.2f\n", salario_medio_suporte);
}