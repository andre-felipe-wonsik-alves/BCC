#include "recursividade.hpp";
#include <iostream>;

using namespace std;

Recursividade::Recursividade() {};

void print_txt(char *text, int num)
{
    if (num < 10)
    {
        cout << "Texto:" << *text << " ";
        print_txt(text, num++);
    }
};