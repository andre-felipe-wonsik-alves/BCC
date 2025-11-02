#include "insertion-sort.h"

void InsertionSort::sort(std::vector<int> &vec)
{
    for (int index = 0; index < static_cast<int>(vec.size()); index++)
    {
        insertion(vec, index);
    }

    this->print(vec, "Insertion Sort");
}

void InsertionSort::insertion(std::vector<int> &vec, int k)
{
    int i = k - 1;
    int x = vec[k];

    while ((i >= 0) && (vec[i] > x))
    {
        vec[i + 1] = vec[i];
        i--;
    }

    vec[i + 1] = x;
}
