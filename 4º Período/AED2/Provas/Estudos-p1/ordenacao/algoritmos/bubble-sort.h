#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include "IAlgoritmo.h"
#include <vector>

class BubbleSort : public IAlgoritmo
{
public:
    void sort(std::vector<int> &vec) override;
};

#endif
