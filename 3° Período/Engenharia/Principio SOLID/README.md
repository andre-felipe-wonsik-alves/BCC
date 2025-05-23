# Princípios SOLID

Os 4 princípios escolhidos foram:
1. Responsabilidade única
2. Inversão de dependência
3. Princípio da segregação de interfaces
4. Demeter

---

## Responsabilidade única
Fazer com que cada parte do código tenha apenas **uma única** responsabilidade ou ideia a ser desenvolvida.

Por exemplo, esta função está com duas responsabilidades (calcular e imprimir):
```java
class Disciplina{
	void calculaIndiceDesistencia(){
		indice = ... <- calcula o índice;
		System.out.println("O índice do aluno foi o seguinte: ", indice);
	}
}
```

Colocando-o no princípio:
[exemplos/responsabilidades.java](exemplos/responsabilidades.java)

---

## Inversão de dependência

Sempre utilize interfaces para comunicações entre classes.

**Ao invés disto:**
```java
class A{
	B teste;
	imprimeCalculo(){
		B.calcula();
	}
}

class B {
	int calcula(){
		...
	}
}
```
> Nesse caso, a classe A depende inteiramente de B. Isso diminui a flexibilidade do código.

**Usar isto:**
[exemplos/inversaoDependencias.java](exemplos/inversaoDependencias.java)

> Agora fazemos a classe B depender de uma interface e que A fique livre dessa dependência direta.

---

## Princípio da segregação de interfaces
As interfaces de um sistema devem ser divididas em interfaces menores e mais específicas, em vez de uma única interface grande.

Ao invés disto:
```java
 interface Animal {
     void comer();
     void dormir();
     void voar();
	 void cavar()
 }
```
> Aqui, percebe-se que "Animal" possui várias responsabilidades

**Usar isto:**
[exemplos/interfaces.java](exemplos/interfaces.java)

Assim, sua implementação fica mais clara e objetiva. Por exemplo:
```java
	class Arara implements Animal, Ave{...}

	class Gato implements Animal {...}

	class Rato implements Animal, Roedor {...}
```
---

## Demeter
Evitar encadeamento de métodos.

**Por exemplo, ao invés disso:**
```java
void sendMail(ContaBancaria conta, String msg) {
   Cliente cliente = conta.getCliente();
   String endereco = cliente.getMailAddress();
   "Envia mail"
 }
```
> Aqui, há um encadeamento implícito; seria o mesmo que usar String endereco = conta.get().getMailAddress()

**Usar isto**:
[exemplos/demeter.java](exemplos/demeter.java)

> Dessa maneira, reduzimos a quantidade de encadeamentos

---