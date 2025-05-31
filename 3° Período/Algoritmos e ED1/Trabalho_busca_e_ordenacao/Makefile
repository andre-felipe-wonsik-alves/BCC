all:
	g++ -c ordenacao.cpp
	g++ -c gerador_dados.cpp
	g++ -c main.cpp
	g++ ordenacao.o main.o -o main
	g++ gerador_dados.o main.o -o main
clean:
	rm lista_circular.o main.o main