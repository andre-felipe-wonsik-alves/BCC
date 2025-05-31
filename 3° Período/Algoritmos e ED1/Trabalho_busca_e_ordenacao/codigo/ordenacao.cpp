#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <fstream>
#include <random>
#include <chrono>

using namespace std;

class Ordenacao
{
private:
    vector<int> dados;

    Ordenacao(vector<int> &_arr)
    {
        this->dados = _arr;
    }

    void selection_sort()
    {
        vector<int> copia = this->dados;
        int tamanho = copia.size();
        int index_minimo;

        for (int i = 0; i < tamanho; i++)
        {
            int index_minimo = i;

            for (int j = i + 1; j < tamanho; j++)
            {
                if (copia[j] < copia[index_minimo])
                    index_minimo = j;
            }

            this->swap(&copia[index_minimo], &copia[i]);
        }
    }

    void insertion_sort()
    {
        vector<int> copia = this->dados;
        int tamanho = copia.size();

        for (int i = 1; i < tamanho; i++) // consideramos que o primeiro elemento esta ordenado
        {
            int temp = copia[i];
            int j = i--;

            while (j >= 0 && temp < copia[j])
            {
                copia[j + 1] = copia[j];
                --j;
            }

            copia[j + 1] = temp;
        }
    }

    void bubble_sort()
    {
    }

    void swap(int *elem_A, int *elem_B)
    {
        int temp = *elem_A;
        *elem_A = *elem_B;
        *elem_B = temp;
    }
};
