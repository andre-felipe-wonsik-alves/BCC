# Lista encadeada

Criado em: 04/04/2025

---

## Pontos principais

- Acesso sequencial;
- Não permite acesso aleatório;
- **Bom** para inserção e remoção de quaisquer partes.

```c++
head -> |3| -> |8| -> |2| -> |5| -> __ (nullptr)
```

### Nodes

```c++
class Node {
    public:
        int key;
        Node* next;
};

class LinkedList {
    private:
        Node* head;
        ...
};
```
