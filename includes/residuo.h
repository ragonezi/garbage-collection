#ifndef RESIDUO_H
#define RESIDUO_H

#include <string>

class Residuo
{
private:
  std::string nome;
  std::string armazenamento;
  int tipo;

public:
  Residuo();
  Residuo(std::string, std::string, int);
  void setNome(std::string);
  void setArmazenamento(std::string);
  void setTipo(int);
  std::string getNome();
  std::string getArmazenamento();
  int getTipo();
};

#endif