#include <iostream>
#include <vector>
#include <string>

#include "./POO.hpp"

void Tela::adicione(Digito digito)
{
    switch (digito)
    {
    case ZERO:
        std::cout << "zero";
        break;
    case UM:
        std::cout << "um";
        break;
    case DOIS:
        std::cout << "dois";
        break;
    case TRÊS:
        std::cout << "tres";
        break;
    case QUATRO:
        std::cout << "qautro";
        break;
    case CINCO:
        std::cout << "cinco";
        break;
    case SEIS:
        std::cout << "seis";
        break;
    case SETE:
        std::cout << "sete";
        break;
    case OITO:
        std::cout << "oito";
        break;
    case NOVE:
        std::cout << "nove";
        break;
    default:
        std::cout << "Digito ainda não implementado\n";
        break;
    }
}

void Tela::limpe() {}

void Tecla::pressione() {}

void Teclado::adicioneTecla(Tecla &tecla) { teclas.push_back(&tecla); }

Pessoa::Pessoa(float peso)
{
    this->setPeso(peso);
}

void Pessoa::setPeso(float peso)
{
    if (peso > 0 && peso < 595)
    {
        this->peso = peso;
    }
    else
    {
        std::cerr << "ERRO: Pessoa.setPeso() - Peso inválido\n";
    }
}

float Pessoa::getPeso() { return this->peso; }