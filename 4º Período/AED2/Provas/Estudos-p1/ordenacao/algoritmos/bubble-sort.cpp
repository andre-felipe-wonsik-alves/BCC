#include "bubble-sort.h"
#include <algorithm>

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
