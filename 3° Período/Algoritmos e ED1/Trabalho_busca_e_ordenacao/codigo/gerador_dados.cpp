#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <fstream>
#include <random>
#include <chrono>

using namespace std;

// https://www.youtube.com/watch?v=YG4jexlSAjc <- benchmark baseado nesse tutorial
class Timer {
    public:
        Timer(){
            tempo_inicial = std::chrono::high_resolution_clock::now();
        }

        ~Timer(){
            Stop();
        }

        void Stop(){
            auto tempo_final= std::chrono::high_resolution_clock::now();

            std::chrono::duration<double> duracao = tempo_final - this->tempo_inicial;

            cout << "Duração: " << duracao.count() << " segundos \n";
        }
        private:
            std::chrono::time_point<std::chrono::high_resolution_clock> tempo_inicial;
};

void create_ordered_file(int file_size)
{
    fstream file;
    file.open("./dados/ordenado_" + to_string(file_size) + ".bin", ios::binary | ios::out);

    for (int i = file_size; i > 0; i--)
    {
        file.write(reinterpret_cast<char*>(&i), sizeof(int));
    }

    file.close();
}

void create_unordered_file(int file_size)
{
    fstream file;
    file.open("./dados/nao_ordenado_" + to_string(file_size)+ ".bin", ios::binary | ios::out);

    int random = rand() % 9999;

    for (int i = file_size; i >= 0; i--)
    {
        file.write(reinterpret_cast<char*>(&i), sizeof(int));
        random = rand() % 9999;
    }

    file.close();
}

int main()
{
    Timer time;
    int pequeno = 10000;
    int medio = 50000;
    int grande = 120000;
    // create_unordered_file(100);    
    create_ordered_file(100);

    return 0;
}