#include <stdlib.h>
#include <iostream>
#include "user.h"
#include "conexao.h"

int main()
{
	try
	{
		Conexao *con = new Conexao();
		std::cout << "OK, conectado ao banco!" << std::endl;
	}
	catch (const char *e)
	{
		std::cerr << e << std::endl;
	}
	catch (...)
	{
		std::cerr << "Erro inesperado!" << std::endl;
	}
	system("PAUSE");
	return 0;
}

void tela_inicial()
{
	int opc = 0;

	std::cout << "SISTEMA DE GESTÃO DE RESÍDUOS" << std::endl;
	std::cout << "1.Login" << std::endl;
	std::cout << "2.Cadastro \n"
			  << std::endl;
	std::cout << "Digite a opcao desejada: " << std::endl;
	std::cin >> opc;

	if (opc == 1)
	{
		/* chamar login: */
	}
	else
	{
		usuario a;
		a.set_nome();
		a.set_CPF();
		std::cout << "o usuario a e:" << std::endl;
		std::cout << a.get_nome() << "/" << a.get_CPF() << std::endl;
	}
}