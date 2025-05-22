class Disciplina{
	void calculaIndiceDesistencia(){
		indice = ... <- calcula o índice;
		System.out.println("O índice do aluno foi o seguinte: ", indice);
	}
}

// COM RESPONSABILIDADE ÚNICA
class Disciplina{
	void calculaIndiceDesistencia(){
		indice = ... <- calcula o índice;
	}
	void imprimeIndice(){
		System.out.println("O índice do aluno foi o seguinte: ", indice);
	}
}