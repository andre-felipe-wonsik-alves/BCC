#include "lista.h"

ListaEncadeada::ListaEncadeada(){
    this->tamanho = 0;
    this->primeiro = nullptr;
    this->ultimo = nullptr;
}

void ListaEncadeada::inserir(int valor){
    No* novo = new No(valor);

    if(this->vazia()){
        this->primeiro = novo;
    } else {
        this->ultimo->proximo = novo;
    }
    
    this->ultimo = novo;
    this->tamanho++;
}