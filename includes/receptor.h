#ifndef RECEPTOR_H
#define RECEPTOR_H

#include "pessoa.h"

class Receptor : public Pessoa
{
  public:
    Receptor();
    Receptor(std::string, std::string, std::string, std::string);
};

#endif