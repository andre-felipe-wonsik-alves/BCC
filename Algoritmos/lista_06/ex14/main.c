#include <stdio.h>

int string_to_int(const char str[])
{
    int result = 0;
    int i = 0;

    while (str[i] != '\0')
    {
        if (str[i] >= '0' && str[i] <= '9')
        {

            result = result * 10 + (str[i] - '0');
        }
        else
        {

            break;
        }
        i++;
    }

    return result;
}

int main()
{
    const char s1[] = "2506";
    printf("String: %s -> Inteiro: %d\n", s1, string_to_int(s1));

    return 0;
}
