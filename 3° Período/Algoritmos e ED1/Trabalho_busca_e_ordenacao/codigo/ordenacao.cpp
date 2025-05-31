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

public:
    Ordenacao(vector<int> &_arr)
    {
        this->dados = _arr;
        this->copia = this->dados;
        this->tamanho = this->copia.size();
    }

    void selection_sort()
    {
        Utilities util;
        util.count_duration();

        int index_minimo;

        for (int i = 0; i < this->tamanho; i++)
        {
            int index_minimo = i;

            for (int j = i + 1; j < this->tamanho; j++)
            {
                if (this->copia[j] < this->copia[index_minimo])
                    index_minimo = j;
            }

            this->swap(&this->copia[index_minimo], &this->copia[i]);
        }
    }

    void insertion_sort()
    {
        Utilities util;
        util.count_duration();

        for (int i = 1; i < this->tamanho; i++) // consideramos que o primeiro elemento esta ordenado
        {
            int temp = this->copia[i];
            int j = i--;

            while (j >= 0 && temp < this->copia[j])
            {
                this->copia[j + 1] = this->copia[j];
                --j;
            }

            this->copia[j + 1] = temp;
        }
    }

    void bubble_sort()
    {
        Utilities util;
        util.count_duration();

        vector<int> copia = this->dados;
        int tamanho = copia.size();

        for (int i = 0; i < tamanho; i++)
        {
            for (int j = 0; j < tamanho - i; i++)
            {
                if (copia[j] > copia[j + 1])
                {
                    this->swap(&copia[j], &copia[j + 1]);
                }
            }
        }
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
                    this->swap(&copia[j], &copia[j + 1]);
                }
            }

            if (!trocado)
                break;
        }
    }

    void swap(int *elem_A, int *elem_B)
    {
        int temp = *elem_A;
        *elem_A = *elem_B;
        *elem_B = temp;
    }
};
