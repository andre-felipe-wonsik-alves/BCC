#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include "IAlgoritmo.h"
#include <vector>

class SelectionSort : public IAlgoritmo
{
public:
    void sort(std::vector<int> &vec) override;
    int max_in_range(const std::vector<int> &vec, int inicio, int fim);
};

#endif
