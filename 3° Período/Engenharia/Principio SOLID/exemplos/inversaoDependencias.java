class A{
	I teste;
	imprimeCalculo(){
		teste.calcula();
	}

	A(I teste){
		teste = teste;
	}
}

interface I{
	int calcula();
}

class B implements I{
	int calcula(){
		...
	}
}