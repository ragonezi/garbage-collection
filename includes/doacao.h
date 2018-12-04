#ifndef DOACAO_H
#define DOACAO_H

#include <iostream>
#include <vector>
#include "residuo.h"
#include "doador.h"

class Doacao
{
private:
  Residuo residuo;
  Doador doador;
  int quantidade;
  unsigned int disponibilidade;

public:
  Doacao();
  Doacao(Residuo, Doador, int, unsigned int);
  void setResiduo(Residuo);
  void setDoador(Doador);
  void setQuantidade(int);
  void setDisponibilidade(unsigned int);
  Residuo getResiduo();
  Doador getDoador();
  int getQuantidade();
  int getDisponibilidade();
};

#endif