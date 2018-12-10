#ifndef PESSOA_H
#define PESSOA_H

#include <string>

class Pessoa
{

private:
  std::string nome;
  std::string documento;
  std::string telefone;
  std::string endereco;
  std::string idPessoa;

public:
  Pessoa();
  Pessoa(std::string, std::string, std::string, std::string);

  void setNome(std::string);
  void setDocumento(std::string);
  void setTelefone(std::string);
  void setEndereco(std::string);
  void setIdPessoa(std::string);

  std::string getNome();
  std::string getDocumento();
  std::string getTelefone();
  std::string getEndereco();
  std::string getIdPessoa();
};

#endif