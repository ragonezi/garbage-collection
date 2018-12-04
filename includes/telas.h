#ifndef TELAS_H
#define TELAS_H

#include <string>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include "usuario.h"
#include "residuo.h"
#include "doacao.h"
#include "doador.h"

#define CLRSCR "cls"
#define PAUSE "pause"

class Telas
{

public:
  static void telaInicial();
  static Usuario &login();
  static void logout(Usuario &);
  static Usuario &cadastro();
  static void menuPrincipal(Usuario &);
  static void voltarMenuPrincipal(Usuario &);
  static void cadastrarResiduo(Usuario &);

  static Residuo escolherResiduo(int);
  static void cabecalho();
  static void limparTela();

  static int getOpcao(int, int);
  static int getNumero();
  static int getNumeroPositivo();
  static int numero(int &);
};

#endif