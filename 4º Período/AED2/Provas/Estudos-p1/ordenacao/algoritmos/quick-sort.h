#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include "IAlgoritmo.h"
#include <vector>

class QuickSort : public IAlgoritmo
{
public:
    void sort(std::vector<int> &vec, int left, int right) override;
    int partition(std::vector<int> &vec, int limite_menor, int limite_maior);
};

#endif
