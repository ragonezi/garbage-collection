#include <stdlib.h>
#include <iostream>
#include "includes/conexao.h"
#include "includes/usuario.h"
#include "includes/residuo.h"
#include "includes/telas.h"
#include "includes/auxiliar.h"
#include "includes/gerenciamento.h"

int main()
{

	Telas::telaInicial();

	// Gerenciamento conexao = Gerenciamento();

	// std::vector<Doacao> doacoesDisponiveis = conexao.getDoacoes("1", 1);

	// std::vector<Residuo> residuos = conexao.getResiduos(1);
	// int i = 0;
	// for (std::vector<Doacao>::iterator it = doacoesDisponiveis.begin(); it != doacoesDisponiveis.end(); ++it)
	// {
	// 	i++;
	// 	std::cout << " " << i << "." << it->getDoador().getNome() << std::endl;
	// }

	system("PAUSE");

	return 0;
}