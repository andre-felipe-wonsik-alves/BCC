#include <iostream>
#include <vector>
#include <string>

/* Cabeçalho */
class Calculadora;
class Tecla;
class Cpu;
class Teclado;
class Tecla;

enum Digito
{
    ZERO,
    UM,
    DOIS,
    TRÊS,
    QUATRO,
    CINCO,
    SEIS,
    SETE,
    OITO,
    NOVE
};
enum Operacao
{
    SOMA,
    SUBTRAÇÃO,
    MULTIPLICAÇÃO,
    DIVISÃO,
    RADICIAÇÃO,
    PORCENTAGEM
};
enum Controle
{
    LIGA_LIMPA_ERRO,
    DESLIGA,
    MEMÓRIA_SOMA,
    MEMÓRIA_SUBTRAÇÃO,
    MEMÓRIA_LEITURA_LIMPEZA,
    IGUAL,
    PONTO_FLUTUANTE
};

/* Implementações */

class Pessoa
{
private:
    float peso = 0;

public:
    Pessoa(float peso);

    void setPeso(float peso);

    float getPeso();
};

class Tela
{
public:
    void adicione(Digito digito);
    void limpe();
};

class Cpu
{
public:
    Tela *tela;
};

class Tecla
{
public:
    Teclado *teclado;
    void pressione();
};

class Calculadora
{
public:
    Tela *tela;
    Cpu *cpu;
    Teclado *teclado;
};

class Teclado
{
public:
    Cpu *cpu;
    std::vector<Tecla *> teclas;
    void adicioneTecla(Tecla &tecla);
};
