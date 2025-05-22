# Princípios SOLID

Os 4 princípios escolhidos foram:
1. Responsabilidade única
2. Inversão de dependência
3. Princípio do Aberto/Fechado
4. Demeter

---

## Responsabilidade única
Fazer com que cada parte do código tenha apenas **uma única** responsabilidade ou ideia a ser desenvolvida.

Essa função está com duas responsabilidades (calcular e imprimir), por exemplo:
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

**Usar isto:**
[exemplos/inversaoDependencias.java](exemplos/inversaoDependencias.java)

---

## Princípio do Aberto/Fechado
 Uma classe deve estar **fechada** para modificações, mas **aberta** para extensões

- Suponha que você vai implementar uma classe
- Usuários ou clientes vão querer usar a classe (óbvio!)
- Mas vão querer também customizar, parametrizar, configurar, flexibilizar e estender a classe!
- Você deve se antecipar e tornar possível tais extensões
- Mas sem que os clientes tenham que alterar o código da classe

Ao invés disto:
```java
void imprimeDataContratacao(Funcionario func) {
   Date data = func.getDataContratacao();
   String msg = data.format();
   System.out.println(msg);
} 
```

**Usar isto:**
[exemplos/abertoFechado.java](exemplos/abertoFechado.java)

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

**Usar isto**:
[exemplos/demeter.java](exemplos/demeter.java)

---