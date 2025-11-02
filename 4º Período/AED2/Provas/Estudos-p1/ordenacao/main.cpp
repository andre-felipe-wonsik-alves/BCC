#include "algoritmos/selection-sort.h"
#include "algoritmos/bubble-sort.h"
#include "algoritmos/insertion-sort.h"
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<int> v = {5, 6, 8, 1, 3};

    IAlgoritmo *selection = new SelectionSort();
    IAlgoritmo *bubble = new BubbleSort();
    IAlgoritmo *insertion = new InsertionSort();

    selection->sort(v);
    bubble->sort(v);
    insertion->sort(v);

    delete selection;
    delete bubble;
    delete insertion;

    return 0;
}
