#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <fstream>
#include <random>
#include "utilities.cpp"

using namespace std;

class Ordenacao
{
private:
    vector<int> dados;
    vector<int> copia;
    int tamanho = 0;
    Utilities util;

public:
    Ordenacao(vector<int> &_arr)
    {
        this->dados = _arr;
        this->copia = this->dados;
        this->tamanho = this->copia.size();
    }

    void selection_sort()
    {
        for (int i = 0; i < this->tamanho; i++)
        {
            int index_minimo = i;

            for (int j = i + 1; j < this->tamanho; j++)
            {
                if (this->copia[j] < this->copia[index_minimo])
                    index_minimo = j;
            }

            this->util.swap(&this->copia[index_minimo], &this->copia[i]);
        }
        this->printArray(copia);
    }

    void insertion_sort()
    {
        Utilities util;
        util.count_duration();

        for (int i = 1; i < this->tamanho; i++) // consideramos que o primeiro elemento está ordenado
        {
            int temp = this->copia[i];
            int j = i;

            while (j > 0 && temp < this->copia[j - 1])
            {
                this->copia[j] = this->copia[j - 1];
                --j;
            }

            this->copia[j] = temp;
        }
        this->printArray(copia);
    }

    void bubble_sort()
    {
        Utilities util;
        util.count_duration();
        int *iteracoes = new int(0);

        for (int i = 0; i < this->tamanho; i++)
        {
            for (int j = 0; j < this->tamanho - i - 1; j++)
            {
                if (this->copia[j] > this->copia[j + 1])
                {
                    this->util.swap(&this->copia[j], &this->copia[j + 1]);
                }
                util.count_iterations(iteracoes);
            }
        }

        cout << "Número de iterações: " << *iteracoes << endl;

        this->printArray(copia);
    }

    void printArray(vector<int> vec)
    {
        for (int elem : vec)
        {
            cout << elem << "";
        }
        cout << endl;
    }

    void optimized_bubble_sort()
    {
        Utilities util;
        util.count_duration();

        vector<int> copia = this->dados;
        int tamanho = copia.size();
        bool trocado;

        for (int i = 0; i < tamanho; i++)
        {
            trocado = false;

            for (int j = 0; j < tamanho - i; i++)
            {
                if (copia[j] > copia[j + 1])
                {
                    this->util.swap(&copia[j], &copia[j + 1]);
                }
            }

            if (!trocado)
                break;
        }
    }
};
