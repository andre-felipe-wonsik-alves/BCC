#include <iostream>
#include <algorithm>
#include "lista_dp_circular.hpp"

using namespace std;

DoubleCircularList::DoubleCircularList()
{
    this->head = nullptr;
    this->tail = this->head;
}