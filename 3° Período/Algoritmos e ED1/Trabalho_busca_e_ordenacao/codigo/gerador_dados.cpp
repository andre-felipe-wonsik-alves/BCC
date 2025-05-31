#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <random>

using namespace std;

class Gerador
{
    Gerador(int file_size)
    {
        this->size = file_size;
    }

    void create_ordered_file()
    {
        fstream file;
        file.open("./dados/ordenado_" + to_string(this->size) + ".bin", ios::binary | ios::out);

        for (int i = this->size; i > 0; i--)
        {
            file.write(reinterpret_cast<char *>(&i), sizeof(int));
        }

        file.close();
    }

    void create_unordered_file()
    {
        vector<int> dados(this->size);
        fstream file;

        for (int &dado : dados)
        {
            dado = rand() % 9999;
        }

        file.open("./dados/nao_ordenado_" + to_string(this->size) + ".bin", ios::binary | ios::out);
        file.write(reinterpret_cast<char *>(dados.data()), sizeof(int) * dados.size());
        file.close();
    }

private:
    int size = 0;
};
