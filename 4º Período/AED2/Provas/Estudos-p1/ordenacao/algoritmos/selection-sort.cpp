#include "selection-sort.h"
#include <algorithm> // para std::swap

void SelectionSort::sort(std::vector<int> &vec)
{
    for (int index = vec.size() - 1; index > 0; index--)
    {
        int maior = max_in_range(vec, 0, index + 1);
        std::swap(vec[maior], vec[index]);
    }

    this->print(vec, "Selection Sort");
}

int SelectionSort::max_in_range(const std::vector<int> &vec, int inicio, int fim)
{
    int maior = inicio;
    for (int i = inicio + 1; i < fim; i++)
    {
        if (vec[i] > vec[maior])
        {
            maior = i;
        }
    }
    return maior;
}
