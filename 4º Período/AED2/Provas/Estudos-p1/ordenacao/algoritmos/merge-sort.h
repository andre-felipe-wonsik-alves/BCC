#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include "IAlgoritmo.h"
#include <vector>

class MergeSort : public IAlgoritmo
{
public:
    void sort(std::vector<int> &vec, int left, int right) override;
    void merge(std::vector<int> &vec, int left, int mid, int right);
};

#endif
