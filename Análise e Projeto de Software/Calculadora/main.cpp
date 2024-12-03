#include <iostream>
#include <vector>
#include <string>

/** Cabeçalho */
class Calculadora;
class Tecla;
class Cpu;
class Teclado;
class Tecla;

enum Digito{ZERO, UM, DOIS, TRÊS, QUATRO, CINCO, SEIS, SETE, OITO, NOVE};
enum Operacao{SOMA, SUBTRAÇÃO, MULTIPLICAÇÃO, DIVISÃO, RADICIAÇÃO, PORCENTAGEM};
enum Controle{LIGA_LIMPA_ERRO, DESLIGA, MEMÓRIA_SOMA, MEMÓRIA_SUBTRAÇÃO, MEMÓRIA_LEITURA_LIMPEZA, IGUAL, PONTO_FLUTUANTE};


/** Implementações */
class Tela {

  public:
    void adicione(Digito digito){
      switch (digito)
      {
      case ZERO:
        std::cout<<"zero";
        break;
      case UM:
        std::cout<<"um";
        break;
      case DOIS:
        std::cout<<"dois";
        break;
      case TRÊS:
        std::cout<<"tres";
        break;
      case QUATRO:
        std::cout<<"qautro";
        break;
      case CINCO:
        std::cout<<"cinco";
        break;
      case SEIS:
        std::cout<<"seis";
        break;
      case SETE:
        std::cout<<"sete";
        break;
      case OITO:
        std::cout<<"oito";
        break;
      case NOVE:
        std::cout<<"nove";
        break;
      default:
        std::cout<<"Digito ainda não implementado\n";
        break;
      }
    }
    void limpe(){

    }

};

class Cpu {
public:
  Tela *tela;
};

class Tecla {
public:
  Teclado *teclado;
  void pressione() {}
};

class Calculadora {
public:
  Tela *tela;
  Cpu *cpu;
  Teclado *teclado;
};

class Teclado {
public:
  Cpu *cpu;
  std::vector<Tecla *> teclas;
  void adicioneTecla(Tecla &tecla) { teclas.push_back(&tecla); }
};

class Pessoa {
private:
  float peso = 0;

public:

  Pessoa(float peso) {
    this -> setPeso(peso);
  } 

  void setPeso(float peso) {
    if (peso > 0 && peso < 595) {
      this->peso = peso;
    } else {
      std::cerr << "ERRO: Pessoa.setPeso() - Peso inválido\n";
    }
  }

  float getPeso() { return this->peso; }
};

int main() {
  Pessoa p1(10);
  std::cout << "A pessoa p1 pesa " << p1.getPeso() << " kilos." << std::endl;

  Tecla tecla1;
  tecla1.pressione();

  Teclado teclado1;
  teclado1.adicioneTecla(tecla1);

  Tela t1;
  t1.adicione(ZERO);

  std::cout << "All it's okey!\n";
  return 0;
}
