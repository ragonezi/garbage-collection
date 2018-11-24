#include <stdlib.h>
#include <iostream>
#include "user.h"
#include "mysql.h"

int main(void)
{
	MYSQL mysql;

	if (mysql_init(&mysql) == NULL)
	{
		printf("\nInitialization error\n");
		std::cout << "Press enter to continue!\n";
		system("PAUSE");
		return 0;
	}

	if (mysql_real_connect(&mysql, "localhost", "root", "teste", NULL, 0, NULL, 0) == NULL)
	{
		fprintf(stderr, "%s\n", mysql_error(&mysql));
		mysql_close(&mysql);
		system("PAUSE");
		exit(1);
	}

	printf("Client version: %s", mysql_get_client_info());
	printf("\nServer version: %s", mysql_get_server_info(&mysql));
	mysql_close(&mysql);
	system("PAUSE");
	return 1;
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
