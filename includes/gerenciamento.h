#ifndef GERENCIAMENTO_H
#define GERENCIAMENTO_H

#include <string>
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
  MYSQL_RES *resp;
  MYSQL_ROW linhas;
  MYSQL_FIELD *campos;

public:
  Gerenciamento();

  // Metodos gerais
  bool selecionar(std::string);
  int inserir(std::string);
  void limparResultado();

  // Metodos para o usuario
  bool login(Usuario &, std::string);
  bool cadastro(Usuario &, std::string);
  bool disponibilidadeDocumento(std::string);

  // Residuos
  std::vector<Residuo> getResiduos(int);

  // Doacao
  bool cadastrarDoacao(Doacao &);
  std::vector<Doacao> getDoacoes(std::string, int, bool);
  Doacao configurarDoacao(std::vector<std::string>, int);

  // Solicitacao
  bool cadastrarSolicitacao(Solicitacao &);
  std::vector<Solicitacao> getSolicitacoes(std::string, bool);
  Solicitacao configurarSolicitacao(std::vector<std::string>);

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