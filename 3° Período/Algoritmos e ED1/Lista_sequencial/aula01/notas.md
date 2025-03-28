# TAD

**T**ipo **A**bstrato de **D**ados

---

- Define o modelo represetando e as operações possíveis;
- arrays e structs;
- Não define a estratégia de implementação.

## Tipos de dados abstratos

- Lista sequencial
- Lista encadeada
- Lista Duplamente encadeada
- Lista circular
- Fila
- Pilha

---

## Lista sequencial

- É, basicamente, um array dinâmico
  - Dinâmico em relação ao tamanho
- Permite acessos aleatórios e por índice

Exemplo: [1,2,3,4,5]

> Percebe-se como é ruim para realizar inserções no início da lista, visto que todos os elementos teriam que ser realocados

### Implementação

- Vetor alocado em *Heap*
  - Capacidade do vetor == tamanho real do vetor
  - Tamanho da lista == quantidade de elemetnos na lista
  - Ponteiros para o vetor alocado em *heap*
