#include <stdio.h>
#include <cmath>
#include <iostream>

unsigned int string_hash(char *c, int K)
{
    unsigned int sum = 0;
    for (int i = 0; c[i] != '\0'; i++)
    {
        sum += c[i] * pow(K, i);
    }
    std::cout << "HASH STRING: " << sum;
    return sum;
}

unsigned int hash(int number, int m)
{
    std::cout << "HASH FINAL: " << number % m;
    return number % m;
}

int main()
{
    unsigned int res = string_hash("ABC", 31);
    unsigned int pos = hash(res, 37);

    return 0;
}
