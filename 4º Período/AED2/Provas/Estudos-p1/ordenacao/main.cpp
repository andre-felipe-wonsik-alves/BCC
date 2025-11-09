#include "algoritmos/selection-sort.h"
#include "algoritmos/bubble-sort.h"
#include "algoritmos/insertion-sort.h"
#include "algoritmos/merge-sort.h"
#include "algoritmos/quick-sort.h"
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<int> v = {5, 6, 8, 1, 3};

    BubbleSort *bubble = new BubbleSort();
    SelectionSort *selec = new SelectionSort();
    InsertionSort *insert = new InsertionSort();
    QuickSort *quick = new QuickSort();

    bubble->decrescent_sort(v);
    selec->decrescent_sort(v);

    insert->sort(v);
    quick->sort(v, 0, v.size() - 1);
    return 0;
}
