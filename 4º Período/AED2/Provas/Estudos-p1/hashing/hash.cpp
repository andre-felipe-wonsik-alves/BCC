/*
Resolvendo a lista de exercícios de AED2, encontrada no link:
https://moodle.utfpr.edu.br/pluginfile.php/3066836/mod_resource/content/1/problemas_hashing.pdf
*/

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include <iostream>

std::unordered_map<int, int> contarFrequencia(std::vector<int> &vec)
{
    std::unordered_map<int, int> frequencia;

    for (int elem : vec)
    {
        frequencia[elem]++;
    }

    return frequencia;
}

int primeiroUnico(std::vector<int> &arr)
{
    std::unordered_map<int, int> frequencia = contarFrequencia(arr);
    int elem_unico;

    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (frequencia[arr[i]] == 1)
        {
            return i;
        }
    }

    return -1;
}

std::pair<int, int> twoSum(std::vector<int> &arr, int k)
{
    /*
    Fiz uma implementação que funciona, mas que claramente não é otimizada.

    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = i + 1; j < arr.size() - 1; j++)
        {
            if (arr[i] + arr[j] == k)
            {
                return {arr[i], arr[j]};
            }
        }
    }

    Esse for duplo indica um crescimento O(n²) e isso é um problema.
    Então, precisei pensar bem mais para chegar nisso:

    */

    std::unordered_set<int> verificados;

    for (int elem : arr)
    {
        int complemento = k - elem;

        if (verificados.find(complemento) != nullptr)
        {
            return {complemento, elem};
        }

        verificados.insert(elem);
    }

    return {-1, -1};
}

bool temDuplicatas(std::vector<int> &arr)
{
    std::unordered_set<int> valores;

    for (int elem : arr)
    {
        if (valores.find(elem) != nullptr)
        {
            return true;
        }

        valores.insert(elem);
    }

    return false;
}

std::vector<int> semDuplicatas(std::vector<int> &arr)
{
    std::unordered_set<int> mapa;
    std::vector<int> saida;

    for (int elem : arr)
    {
        if (mapa.find(elem) == nullptr)
        {
            mapa.insert(elem);
            saida.push_back(elem);
        }
    }

    return saida;
}

std::vector<std::vector<std::string>> agruparAnagramas(const std::vector<std::string> &palavras)
{
    std::unordered_map<std::string, std::vector<std::string>> grupos;

    for (const std::string &palavra : palavras)
    {
        std::string chave = palavra;
        std::sort(chave.begin(), chave.end());

        grupos[chave].push_back(palavra);
    }

    std::vector<std::vector<std::string>> resultado;

    for (auto &par : grupos)
    {
        resultado.push_back(par.second);
    }

    return resultado;
}

int maiorSequenciaConsecutivos(std::vector<int> &arr)
{
    std::unordered_set<int> mapa;
    int maior;

    for (int elem : arr)
    {
        mapa.insert(elem);
    }

    for (int x : mapa)
    {
        if (mapa.find(x - 1) == mapa.end())
        {
            int atual = x;
            int comprimento = 1;

            while (mapa.find(atual + 1) != mapa.end())
            {
                atual++;
                comprimento++;
            }

            if (comprimento > maior)
            {
                maior = comprimento;
            }
        }
    }

    return maior;
}

bool temSubvetorSomaZero(std::vector<int> &arr)
{
    std::unordered_set<int> dict;
    int sum = 0;

    for (int elem : arr)
    {
        sum += elem;

        if (sum == 0 || (dict.find(sum) != nullptr))
            return true;

        dict.insert(sum);
    }
    return false;
}

bool temSubvetorSomaK(std::vector<int> &arr, int k)
{
    std::unordered_set<int> dict;
    int sum = 0;

    for (int elem : arr)
    {
        sum += elem;

        if (sum == k || (dict.find(sum) != nullptr))
            return true;

        dict.insert(sum);
    }

    return false;
}

bool saoIguais(std::vector<int> &arr1, std::vector<int> &arr2)
{
    std::unordered_set<int> dict;

    for (int elem : arr1)
    {
        dict.insert(elem);
    }

    for (int elem : arr2)
    {
        if (dict.find(elem) == nullptr)
            return false;
    }

    return true;
}

std::vector<int> uniao(std::vector<int> &arr1, std::vector<int> &arr2)
{
    std::unordered_set<int> dict;
    std::vector<int> out;

    for (int elem : arr1)
    {
        dict.insert(elem);
    }

    for (int elem : arr2)
    {
        dict.insert(elem);
    }

    for (auto cell : dict)
    {
        out.push_back(cell);
    }

    return out;
}

std::vector<int> intersecao(std::vector<int> &arr1, std::vector<int> &arr2)
{
    std::unordered_set<int> dict;
    std::vector<int> out;

    for (int elem : arr1)
    {
        dict.insert(elem);
    }

    for (int elem : arr2)
    {
        if (dict.find(elem) != nullptr)
            out.push_back(elem);
    }

    return out;
}

std::vector<int> diferenca(std::vector<int> &arr1, std::vector<int> &arr2)
{
    std::unordered_set<int> dict;
    std::vector<int> out;

    for (int elem : arr1)
    {
        dict.insert(elem);
    }

    for (int elem : arr2)
    {
        if (dict.find(elem) == nullptr)
            out.push_back(elem);
    }

    return out;
}

bool ehSubconjunto(std::vector<int> &arr1, std::vector<int> &arr2)
{
    std::unordered_set<int> dict;

    for (int elem : arr2)
    {
        dict.insert(elem);
    }

    for (int elem : arr1)
    {
        if (dict.find(elem) == nullptr)
            return false;
    }

    return true;
}

bool saoDisjuntos(std::vector<int> &arr1, std::vector<int> &arr2)
{
    std::unordered_set<int> dict;

    for (int elem : arr1)
    {
        dict.insert(elem);
    }

    for (int elem : arr2)
    {
        if (dict.find(elem) != nullptr)
            return false;
    }

    return true;
}

std::vector<int> diferencaSimetrica(std::vector<int> &arr1, std::vector<int> &arr2)
{
    std::unordered_set<int> dict1, dict2;
    std::vector<int> out;

    for (int elem : arr1)
    {
        dict1.insert(elem);
    }

    for (int elem : arr2)
    {
        dict2.insert(elem);
    }

    for (int cell : dict1)
        if (dict2.find(cell) == dict2.end())
            out.push_back(cell);

    for (int cell : dict2)
        if (dict1.find(cell) == dict1.end())
            out.push_back(cell);

    return out;
}

int main()
{
    std::vector<int> vec = {1, 1, 2, 100, 3, 555, 4, 1, 1, 1};
    std::vector<int> vec2 = {1, 1, 2, 12, 13};
    std::vector<std::string> palavras = {"ate", "eat", "tea", "bat", "tab"};
    // std::vector<int> vec = {1, 2, 5, 6};

    std::unordered_map<int, int> res = contarFrequencia(vec);

    int unico = primeiroUnico(vec);

    std::pair<int, int> pair = twoSum(vec, 6);

    bool duplicatas = temDuplicatas(vec);

    std::vector<int> semDup = semDuplicatas(vec);

    agruparAnagramas(palavras);

    maiorSequenciaConsecutivos(vec);

    temSubvetorSomaZero(vec);

    temSubvetorSomaK(vec, 5);

    saoIguais(vec, vec2);

    uniao(vec, vec2);

    intersecao(vec, vec2);

    diferenca(vec, vec2);

    ehSubconjunto(vec2, vec);

    saoDisjuntos(vec, vec2);
    return 0;
}