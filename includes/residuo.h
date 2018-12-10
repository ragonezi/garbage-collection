#ifndef RESIDUO_H
#define RESIDUO_H

#include <string>

class Residuo
{
private:
  std::string nome;
  std::string armazenamento;
  int tipo;
  std::string idResiduo;

public:
  Residuo();
  Residuo(std::string, std::string, int);
  void setNome(std::string);
  void setArmazenamento(std::string);
  void setTipo(int);
  void setIdResiduo(std::string);

  std::string getNome();
  std::string getArmazenamento();
  int getTipo();
  std::string getIdResiduo();
};

#endif