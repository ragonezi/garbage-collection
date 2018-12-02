#ifndef DOADOR_H
#define DOADOR_H

#include "pessoa.h"

class Doador : public Pessoa
{
  public:
    Doador();
    Doador(std::string, std::string, std::string, std::string);
};

#endif