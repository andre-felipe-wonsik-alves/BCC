#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "IAlgoritmo.h"
#include <vector>

class InsertionSort : public IAlgoritmo
{
public:
    void sort(std::vector<int> &vec) override;
    void decrescent_sort(std::vector<int> &vec);

private:
    void insertion(std::vector<int> &vec, int k);
};

#endif
