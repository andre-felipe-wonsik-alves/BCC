#include <stdio.h>

void upper(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32;
        }
    }
}

int main()
{
    char string[] = "Fala fi?";

    upper(string);

    printf("%s\n", string);
    return 0;
}