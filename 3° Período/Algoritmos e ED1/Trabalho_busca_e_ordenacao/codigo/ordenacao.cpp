#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <fstream>
#include <random>
#include <chrono>

using namespace std;

class Ordenacao {
    vector<int> dados;

    Ordenacao(vector<int> &_arr){
        this->dados = _arr;
    }

    void selection_sort(){
        vector<int> copia = this->dados;
        int minimum_index = copia[0];
        int tamanho = copia.size()

        for(int step = 0; step < size - 1; step++) {
            int min_idx = step;
            for (int i = step + 1; i < size; i++) {

            // To sort in descending order, change > to < in this line.
            // Select the minimum element in each loop.
            if (array[i] < array[min_idx])
                min_idx = i;
            }

            // put min at the correct position
            swap(&array[min_idx], &array[step]);
        }
    }
};
