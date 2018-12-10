#ifndef TELAS_H
#define TELAS_H

#include <string>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include "gerenciamento.h"
#include "auxiliar.h"
#include "usuario.h"
#include "residuo.h"
#include "doacao.h"
#include "doador.h"

#define CLRSCR "cls"
#define PAUSE "pause"

class Telas
{

private:
  static Gerenciamento conexao;

public:
  static void telaInicial();
  static Usuario &login();
  static void logout(Usuario &);
  static Usuario &cadastro();
  static void menuPrincipal(Usuario &);
  static void cadastrarResiduo(Usuario &);

  static int escolherTipoResiduo();
  static Residuo escolherResiduo(int);

  static void cadastrarSolicitacao(Usuario &);

  static int escolherDoacao(std::vector<Doacao>);
  static void dadosDoacao(Doacao);

  static void doacoesCadastradas(Usuario &);
  static int escolherMinhaDoacao(std::vector<Doacao>);

  static void listaSolicitacoes(Usuario &);
  static void dadosSolicitacao(Solicitacao, bool);

  static void rankingDoadores(Usuario &);

  static void cabecalho();
};

#endif