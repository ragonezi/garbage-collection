#ifndef TELAS_H
#define TELAS_H

#include <string>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include "usuario.h"

#define CLRSCR "cls"

class Telas
{

  public:
    static void telaInicial();
    static Usuario &login();
    static void logout(Usuario &);
    static Usuario &cadastro();
    static Usuario &menuPrincipal(Usuario);
    static void cadastrarResiduo(Usuario &);

    static void cabecalho();
    static void limparTela();
    static int getOpcao(int, int);
    static int getNumero(int &);
};

#endif