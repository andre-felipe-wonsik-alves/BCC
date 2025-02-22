#include <stdio.h>

void lerUnidade(int unidade)
{
    switch (unidade)
    {
    case 49:
        printf("um ");
        break;
    case 50:
        printf("dois ");
        break;
    case 51:
        printf("três ");
        break;
    case 52:
        printf("quatro ");
        break;
    case 53:
        printf("cinco ");
        break;
    case 54:
        printf("seis ");
        break;
    case 55:
        printf("sete ");
        break;
    case 56:
        printf("oito ");
        break;
    case 57:
        printf("nove ");
        break;
    default:
        break;
    }
}

void lerCentena(int centena)
{
    switch (centena)
    {
    case 49:
        printf("cento");
        break;
    case 50:
        printf("duzentos ");
        break;
    case 51:
        printf("trezentos ");
        break;
    case 52:
        printf("quatrocentos ");
        break;
    case 53:
        printf("quinhentos ");
        break;
    case 54:
        printf("seiscentos ");
        break;
    case 55:
        printf("setecentos ");
        break;
    case 56:
        printf("oitocentos ");
        break;
    case 57:
        printf("novecentos ");
        break;
    default:
        break;
    }
}

int lerDezena(int dezena, int unidade)
{
    switch (dezena)
    {
    case 49:
        switch (unidade)
        {
        case 48:
            printf("dez");
            return 1;
            break;
        case 49:
            printf("onze");
            return 1;
            break;
        case 50:
            printf("doze");
            return 1;
            break;
        case 51:
            printf("treze");
            return 1;
            break;
        case 52:
            printf("quatorze");
            return 1;
            break;
        case 53:
            printf("quinze");
            return 1;
            break;
        case 54:
            printf("dezesseis");
            return 1;
            break;
        case 55:
            printf("dezessete");
            return 1;
            break;
        case 56:
            printf("dezoito");
            return 1;
            break;
        case 57:
            printf("dezenove");
            return 1;
            break;

        default:
            break;
        }
        break;
    case 50:
        printf("vinte ");
        break;
    case 51:
        printf("trinta ");
        break;
    case 52:
        printf("quarenta ");
        break;
    case 53:
        printf("cinquenta ");
        break;
    case 54:
        printf("sessenta ");
        break;
    case 55:
        printf("setenta ");
        break;
    case 56:
        printf("oitenta ");
        break;
    case 57:
        printf("noventa ");
        break;
    default:
        break;
    }
    return 0;
}

void lerSinal(char sinal)
{
    if (sinal == 45)
    {
        printf("(Negativo) ");
    }
    else
    {
        printf("(Positivo) ");
    }
}

int main()
{
    int centena, dezena, dezenaComposta, unidade;
    char strNumero[5];

    printf("Digite um número:\n> ");
    scanf("%s", &strNumero);

    lerSinal(strNumero[0]);
    for (int i = 0; strNumero[i] != '\0'; i++)
    {
        if (i == 1)
        {
            lerCentena(strNumero[i]);
            printf(" e ");
        }
        else if (i == 2)
        {
            lerDezena(strNumero[i], strNumero[i + 1]);
        }
        else
        {
            lerUnidade(strNumero[i]);
        }
    }

    // lerCentena(centena);
    // printf("e ");
    // dezenaComposta = lerDezena(dezena, unidade);
    // if (!dezenaComposta)
    // {
    //     lerUnidade(unidade);
    // }
    // printf("\n");

    return 0;
}
