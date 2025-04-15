#include <iostream>
#include <algorithm>
#include "lista_circular.hpp"

using namespace std;

CircularList::CircularList()
{
    this->head = nullptr;
    this->tail = this->head;
}