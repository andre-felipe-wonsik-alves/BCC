#include <stdio.h>

void printString(char string[])
{
    for (int i = 0; string[i] != '\0'; i++)
    {
        printf("%c ", string[i]);
    }
    printf("\n");
}

int main()
{
    char string[] = "andrezao";

    printString(string);
    return 0;
}