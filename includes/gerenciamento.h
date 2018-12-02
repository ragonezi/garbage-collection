#ifndef GERENCIAMENTO_H
#define GERENCIAMENTO_H

#include "conexao.h"
#include "usuario.h"
#include "residuo.h"
#include "doacao.h"
#include "solicitacao.h"

class Gerenciamento : public Conexao
{
private:
  std::string consulta;
  std::string insercao;
  std::string exclusao;

public:
  Gerenciamento();
  // Metodos para o usuario
  Usuario login(std::string, std::string);
  bool cadastro(Usuario);
  Residuo residuosInteresse(int);
  Doacao doacoesUsuario(int);
  Doacao doacoesResiduo(int);
  Solicitacao solicitacoesUsuario(int);
  Solicitacao solicitacoesDoacao(int);
  // Metodos gerais
  Residuo residuos();
  Doacao doacoes();
};

#endif