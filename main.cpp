#include <iostream>
#include "user.h"

int main ()
{
	int opc=0;

	std::cout << "SISTEMA DE GESTÃO DE RESÍDUOS" << std::endl;
	std::cout << "1.Login" << std::endl;
	std::cout << "2.Cadastro \n" << std::endl;
	std::cout << "Digite a opcao desejada: " << std::endl;
	std::cin >> opc;

	if (opc==1)
	{
		/* chamar login: */
	}
	else
	{ 
		usuario a;	
		a.set_nome();
		a.set_CPF();
		a.set_endereco();
		a.set_telefone();
		std::cout << "o usuario a e:" << std::endl;
		std::cout << a.get_nome() << "/" << a.get_CPF() << "/" << a.get_endereco() << "/" << a.get_telefone() << std::endl;
	}

	return 0;
}