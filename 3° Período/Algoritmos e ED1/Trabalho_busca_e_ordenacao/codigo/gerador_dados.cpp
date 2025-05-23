#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <fstream>
#include <random>

using namespace std;
void create_ordered_file(int file_size)
{
    fstream file;
    file.open("./dados/ordenado.txt", ios::binary | ios::out);

    int random = rand() % 9999;
    int before = random;

    for (int i = file_size; i >= 0; i--)
    {
        if (random >= before)
        {
            file << random;
            file << ".";
        }
        before = random;
        random = rand() % 9999;
    }

    file.close();
}

void create_unordered_file(int file_size)
{
    fstream file;
    file.open("./dados/nao_ordenado.txt", ios::binary | ios::out);

    int random = rand() % 9999;

    for (int i = file_size; i >= 0; i--)
    {
        file << random;
        random = rand() % 9999;
    }

    file.close();
}

int main()
{
    // create_unordered_file(100);
    create_ordered_file(100);

    return 0;
}