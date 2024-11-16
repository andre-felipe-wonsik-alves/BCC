#include <stdio.h>

void lerUnidade(int unidade)
{
    switch (unidade)
    {
    case 1:
        printf("um ");
        break;
    case 2:
        printf("dois ");
        break;
    case 3:
        printf("três ");
        break;
    case 4:
        printf("quatro ");
        break;
    case 5:
        printf("cinco ");
        break;
    case 6:
        printf("seis ");
        break;
    case 7:
        printf("sete ");
        break;
    case 8:
        printf("oito ");
        break;
    case 9:
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
    case 1:
        printf("cento");
        break;
    case 2:
        printf("duzentos ");
        break;
    case 3:
        printf("trezentos ");
        break;
    case 4:
        printf("quatrocentos ");
        break;
    case 5:
        printf("quinhentos ");
        break;
    case 6:
        printf("seiscentos ");
        break;
    case 7:
        printf("setecentos ");
        break;
    case 8:
        printf("oitocentos ");
        break;
    case 9:
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
    case 1:
        switch (unidade)
        {
        case 0:
            printf("dez");
            return 1;
            break;
        case 1:
            printf("onze");
            return 1;
            break;
        case 2:
            printf("doze");
            return 1;
            break;
        case 3:
            printf("treze");
            return 1;
            break;
        case 4:
            printf("quatorze");
            return 1;
            break;
        case 5:
            printf("quinze");
            return 1;
            break;
        case 6:
            printf("dezesseis");
            return 1;
            break;
        case 7:
            printf("dezessete");
            return 1;
            break;
        case 8:
            printf("dezoito");
            return 1;
            break;
        case 9:
            printf("dezenove");
            return 1;
            break;

        default:
            break;
        }
        break;
    case 2:
        printf("vinte ");
        break;
    case 3:
        printf("trinta ");
        break;
    case 4:
        printf("quarenta ");
        break;
    case 5:
        printf("cinquenta ");
        break;
    case 6:
        printf("sessenta ");
        break;
    case 7:
        printf("setenta ");
        break;
    case 8:
        printf("oitenta ");
        break;
    case 9:
        printf("noventa ");
        break;
    default:
        break;
    }
    return 0;
}

int main()
{
    int numero, milhar, centena, dezena, unidade;

    printf("Digite um número:\n> ");
    scanf("%d", &numero);

    milhar = (numero % 10000) / 1000;
    centena = (numero % 1000) / 100;
    dezena = (numero % 100) / 10;
    unidade = numero % 10;

    // 1 2 3 2
    if (milhar)
    {
        lerUnidade(milhar);
        printf("mil ");
        lerCentena(centena);
        printf("e ");
        lerDezena(dezena, unidade);
        if (!lerDezena)
        {
            lerUnidade(unidade);
        }
        printf("\n");
    }
    return 0;
}
