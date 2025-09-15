
#include <iostream>
#include <algorithm>

using namespace std;

int exponenciacao(int numero, int exp)
{
    if (!exp)
        return 1;

    if (exp > 0)
    {
        return numero * exponenciacao(numero, exp - 1);
    };
    return 1 / numero * exponenciacao(numero, exp * (-1) - 1);
}

int MDC(int numA, int numB)
{
    if (numB == 0)
        return numA;
    return MDC(numB, numA % numB);
}

// Gera permutações recursivamente
void permutar(string &s, int inicio, int i);

// Função principal de permutação
void gerarPermutacoes(string &s, int inicio)
{
    if (inicio == s.size() - 1)
    {
        cout << s << endl;
        return;
    }
    // Inicia a troca a partir do índice 'inicio'
    permutar(s, inicio, inicio);
}

// Simula o loop para troca de posições
void permutar(string &s, int inicio, int i)
{
    if (i >= s.size())
        return;

    swap(s[inicio], s[i]);
    gerarPermutacoes(s, inicio + 1);
    swap(s[inicio], s[i]); // backtrack

    permutar(s, inicio, i + 1); // chamada recursiva como "laço"
}

int main()
{
    // int res = exponenciacao(5, -2);
    // int res = MDC(2, 4);

    string palavra = "ABC";
    cout << "Permutações de " << palavra << ":" << endl;
    gerarPermutacoes(palavra, 0);
    // cout << res << endl;
    return 0;
}