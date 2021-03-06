#ifndef DOACAO_H
#define DOACAO_H

#include <iostream>
#include <vector>
#include "residuo.h"
#include "doador.h"

class Doacao
{
private:
  std::string idDoacao;
  Residuo residuo;
  Doador doador;
  std::string quantidade;
  unsigned int disponibilidade;

public:
  Doacao();
  Doacao(Residuo, Doador, std::string, unsigned int);
  void setResiduo(Residuo);
  void setDoador(Doador);
  void setQuantidade(std::string);
  void setDisponibilidade(unsigned int);
  void setIdDoacao(std::string);

  Residuo getResiduo();
  Doador getDoador();
  std::string getQuantidade();
  int getDisponibilidade();
  std::string getIdDoacao();
};

#endif