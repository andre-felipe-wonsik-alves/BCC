#include <iostream>
#include <vector>
#include <string>

#include "POO.hpp"; // ! import

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
