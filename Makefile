#Makefile coleta seletiva

CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

vpath %.cpp src
vpath %.h include

all:main

main.exe: usuario.o telas.o residuo.o auxiliar.o conexao.o
	$(CXX) $(CXXFLAGS) -o main usuario.o telas.o residuo.o auxiliar.o conexao.o

auxiliar.o: auxiliar.h
	g++ -c auxiliar.cpp

#conexao.o: conexao.h
	#g++ -c conexao.cpp

doacao.o: doacao.h
	g++ -c doacao.cpp

doador.o: doador.h
	g++ -c doador.cpp

'Menu Gustavo.o': stdlib.h
	g++ -c 'Menu Gustavo.cpp'

pessoa.o: pessoa.h
	g++ -c pessoa.cpp

receptor.o: receptor.h
	g++ -c receptor.cpp

residuo.o: residuo.h
	g++ -c residuo..cpp

solicitacao.o: solicitacao.h
	g++ -c solicitacao.cpp

telas.o: telas.h
	g++ -c telas.cpp

usuario.o: usuario.cpp usuario.h
	g++ -c usuario.cpp

# Rule for cleaning files generated during compilation.
# Call 'make clean' to use it
clean:
	rm -f main *.o