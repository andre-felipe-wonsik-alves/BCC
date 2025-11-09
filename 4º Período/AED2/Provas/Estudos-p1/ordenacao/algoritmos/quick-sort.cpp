#include "quick-sort.h"
#include <algorithm>
#include <vector>

int QuickSort::partition(std::vector<int> &vec, int limite_menor, int limite_maior)
{
    int repo = vec[limite_maior]; // pivô normal
    // int repo = vec[rand()%limite_maior)] <- pivô aleatório
    /*
    pivô por mediana:
    vector<int> pivots = {limite_menor, limite_maior, (limite_menor + limite_maior)/2};
    insertion->sort(pivots);

    int repo = vec[pivots[1]];

    */
    int i = limite_menor - 1;

    if ((limite_maior - limite_menor) < 20)
    {
        // CHAMARIA O INSERT
        return i + 1; // SEGUNDA VERSAO
    }
    else
    {

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