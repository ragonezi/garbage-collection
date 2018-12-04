#include <stdlib.h>
#include <iostream>
#include "includes/conexao.h"
#include "includes/usuario.h"
#include "includes/residuo.h"
#include "includes/telas.h"

int main()
{
	// try
	// {
	// 	Conexao *con = new Conexao();
	// 	std::cout << "OK, conectado ao banco!" << std::endl;
	// }
	// catch (const char *e)
	// {
	// 	std::cerr << e << std::endl;
	// }
	// catch (...)
	// {
	// 	std::cerr << "Erro inesperado!" << std::endl;
	// }

	// Usuario *usuario = new Usuario("Lucas", "10710045654", "993210509", "Rua Muquicaba");

	// std::cout << usuario->getNome() << std::endl;
	// std::cout << usuario->getDocumento() << std::endl;
	// std::cout << usuario->getTelefone() << std::endl;
	// std::cout << usuario->getEndereco() << std::endl;

	// Residuo residuo = Residuo("Pilha", "Local seco com temperatura amena", 1);
	// usuario->addResiduoInteresse(residuo);

	// Residuo residuo2 = Residuo("Lampada", "Local seco com temperatura amena em recipiente coberto", 1);
	// usuario->addResiduoInteresse(residuo2);

	// std::cout << "Residuos:" << std::endl;
	// std::cout << usuario->getResiduosInteresse().front().getArmazenamento() << std::endl;

	// usuario->imprimirResiduosInteresse();
	Telas::telaInicial();

	system("PAUSE");

	return 0;
}

void tela_inicial()
{
	// int opc = 0;

	// std::cout << "SISTEMA DE GESTÃO DE RESÍDUOS" << std::endl;
	// std::cout << "1.Login" << std::endl;
	// std::cout << "2.Cadastro \n"
	// 		  << std::endl;
	// std::cout << "Digite a opcao desejada: " << std::endl;
	// std::cin >> opc;

	// if (opc == 1)
	// {
	// 	/* chamar login: */
	// }
	// else
	// {
	// 	usuario a;
	// 	a.set_nome();
	// 	a.set_CPF();
	// 	std::cout << "o usuario a e:" << std::endl;
	// 	std::cout << a.get_nome() << "/" << a.get_CPF() << std::endl;
	// }
}