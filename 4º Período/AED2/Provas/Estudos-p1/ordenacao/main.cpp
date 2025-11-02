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
    int left = std::distance(v.begin(), v.begin());
    int right = std::distance(v.begin(), v.end()) - 1;

    IAlgoritmo *selection = new SelectionSort();
    IAlgoritmo *bubble = new BubbleSort();
    IAlgoritmo *insertion = new InsertionSort();
    IAlgoritmo *merge = new MergeSort();
    IAlgoritmo *quick = new QuickSort();

    selection->sort(v);
    bubble->sort(v);
    insertion->sort(v);
    merge->sort(v, left, right);
    quick->sort(v, left, right);

    delete selection;
    delete bubble;
    delete insertion;
    delete merge;
    delete quick;

    return 0;
}
