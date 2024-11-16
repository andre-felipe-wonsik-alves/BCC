#include <stdio.h>

void int_to_string(int number, char converted[])
{
    int index = 0;

    if (number == 0)
    {
        converted[index++] = '0';
    }
    else
    {

        while (number > 0)
        {
            converted[index++] = (number % 10) + '0';
            number /= 10;
        }
    }

    converted[index] = '\0';

    for (int i = 0, j = index - 1; i < j; i++, j--)
    {
        char temp = converted[i];
        converted[i] = converted[j];
        converted[j] = temp;
    }
}

int main()
{
    char num[12];

    int_to_string(512, num);
    printf("%s\n", num);

    return 0;
}
