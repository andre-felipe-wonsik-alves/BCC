#include "bubble-sort.h"

void BubbleSort::sort(std::vector<int> &vec)
{
    for (int i = vec.size() - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (vec[j] > vec[j + 1])
                std::swap(vec[j], vec[j + 1]);
        }
    }

    this->print(vec, "Bubble Sort");
}

void BubbleSort::decrescent_sort(std::vector<int> &vec)
{
    for (int i = 0; i < vec.size() - 1; i++)
    {
        for (int j = 0; j < vec.size() - 1; j++)
        {
            if (vec[j] < vec[j + 1])
                std::swap(vec[j], vec[j + 1]);
        }
    }
    this->print(vec, "Bubble Sort decrescente");
}
