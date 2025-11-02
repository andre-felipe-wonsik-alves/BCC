#ifndef ALGORITMOS_IALGORITMO_H
#define ALGORITMOS_IALGORITMO_H

#include <vector>
#include <string>
#include <iostream>

class IAlgoritmo
{
public:
    virtual void sort(std::vector<int> &vec) = 0;

    void print(const std::vector<int> &vec, const std::string &nome_algoritmo)
    {
        std::cout << "Ordenação usando o algoritmo " << nome_algoritmo << ": { ";
        for (int elem : vec)
        {
            std::cout << elem << " ";
        }
        std::cout << "}" << std::endl;
    }

    virtual ~IAlgoritmo() = default;
};

#endif
