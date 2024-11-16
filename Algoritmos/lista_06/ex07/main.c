#include <stdio.h>

void capitalize(char str[])
{
    int deixarMaiuscula = 1;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (deixarMaiuscula && (str[i] > 'a' && str[i] < 'z'))
        {
            str[i] -= 32;
            deixarMaiuscula = 0;
        }
        else if (!deixarMaiuscula && (str[i] > 'A' && str[i] < 'Z'))
        {
            str[i] += 32;
        }
        else
        {
            deixarMaiuscula = 0;
        }

        if (str[i] == ' ')
        {
            deixarMaiuscula = 1;
        }
    }
}

int main()
{
    char str[] = "welCOME To COMPUTER programming!!";

    capitalize(str);
    printf("%s\n", str);

    return 0;
}