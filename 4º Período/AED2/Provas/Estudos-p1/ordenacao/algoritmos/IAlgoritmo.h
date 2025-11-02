#ifndef ALGORITMOS_IALGORITMO_H
#define ALGORITMOS_IALGORITMO_H

#include <vector>
#include <string>
#include <iostream>

class IAlgoritmo
{
public:
    virtual void sort(std::vector<int> &vec)
    {
        sort(vec, 0, static_cast<int>(vec.size()) - 1);
    }

    virtual void sort(std::vector<int> &vec, int left, int right)
    {
        sort(vec);
    }
    void print(const std::vector<int> &vec, const std::string &nome_algoritmo)
    {
        std::cout << "Ordenação usando o algoritmo " << nome_algoritmo << ": { ";
        for (int elem : vec)
            std::cout << elem << " ";
        std::cout << "}" << std::endl;
    }

    virtual ~IAlgoritmo() = default;
};

#endif
