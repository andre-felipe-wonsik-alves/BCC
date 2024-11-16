#include <stdio.h>

int main()
{
    int numeroFibo;

    printf("Digite um número: \n> ");
    scanf("%d", &numeroFibo);

    for (int i = 0; i <= numeroFibo; i++)
    {
        if (i == 0 || i == 1)
        {
            printf("1\n");
        }
        else if (i == 2)
        {
            printf("2\n");
        }
        else
        {
            printf("%d\n", (i - 1) + (i - 2));
        }
    }

    return 0;
}