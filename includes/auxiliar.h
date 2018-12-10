#ifndef AUXILIAR_H
#define AUXILIAR_H

#include <string>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define CLRSCR "cls"
#define PAUSE "pause"

class Auxiliar
{

public:
  static void pausarSistema();
  static void limparTela();
  static int getOpcao(int, int);
  static int getNumero();
  static int getNumeroPositivo();
  static int numero(int &);
  static std::string getDocumento();
  static int confirmar();
  static int confirmarCadastro();
  static int confirmarSolicitacao();
  static bool validaCNPJ(const int *const);
  static bool validaCPF(const int *const);
};

#endif