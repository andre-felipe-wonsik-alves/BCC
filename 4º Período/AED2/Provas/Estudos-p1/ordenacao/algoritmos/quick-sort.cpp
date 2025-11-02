#include "quick-sort.h"
#include <algorithm>
#include <vector>

int QuickSort::partition(std::vector<int> &vec, int limite_menor, int limite_maior)
{
    int repo = vec[limite_maior]; // pivô
    int i = limite_menor - 1;

    for (int j = limite_menor; j < limite_maior; ++j)
    {
        if (vec[j] <= repo)
        {
            ++i;
            std::swap(vec[i], vec[j]);
        }
    }

    std::swap(vec[i + 1], vec[limite_maior]);
    return i + 1;
}

void QuickSort::sort(std::vector<int> &vec, int esquerda, int direita)
{
    if (esquerda < direita)
    {
        int q = partition(vec, esquerda, direita);
        sort(vec, esquerda, q - 1);
        sort(vec, q + 1, direita);
    }
    this->print(vec, "Quick Sort");
}