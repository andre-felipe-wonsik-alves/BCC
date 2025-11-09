#include "merge-sort.h"

void MergeSort::merge(std::vector<int> &v, int left, int mid, int right)
{
    std::vector<int> temp;

    int i = left, j = mid + 1;

    while (i <= mid && j <= right)
    {
        if (v[i] <= v[j])
            temp.push_back(v[i++]);
        else
            temp.push_back(v[j++]);
        // CAPTURARIA AS INVERSÕES AQUI!
    }
    while (i <= mid)
        temp.push_back(v[i++]);
    while (j <= right)
        temp.push_back(v[j++]);

    for (size_t k = 0; k < temp.size(); ++k)
        v[left + static_cast<int>(k)] = temp[k];
}

void MergeSort::sort(std::vector<int> &vec, int left, int right)
{
    if (left >= right)
        return;

    if (vec[left] > vec[right])
    {
        std::swap(vec[left], vec[right]);
    }

    int mid = left + (right - left) / 2;

    sort(vec, left, mid);
    sort(vec, mid + 1, right);
    merge(vec, left, mid, right);
    this->print(vec, "Merge Sort");
}
