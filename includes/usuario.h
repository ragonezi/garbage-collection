#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include "pessoa.h"
#include "solicitacao.h"

class Usuario : public Pessoa
{

private:
  std::string senha;
  std::vector<Residuo> residuosInteresse;
  std::vector<Doacao> doacoes;
  std::vector<Solicitacao> solicitacoes;

public:
  Usuario();
  Usuario(std::string, std::string, std::string, std::string);
  Usuario(std::string, std::string, std::string, std::string, std::vector<Residuo>);
  Usuario(std::string, std::string, std::string, std::string, std::vector<Residuo>, std::vector<Doacao>, std::vector<Solicitacao>);

  void setSenha(std::string);
  void setResiduosInteresse(std::vector<Residuo>);
  void setSolicitacoes(std::vector<Solicitacao>);
  void setDoacoes(std::vector<Doacao>);

  std::string getSenha();
  std::vector<Residuo> &getResiduosInteresse();
  std::vector<Solicitacao> getSolicitacoes();
  std::vector<Doacao> getDoacoes();

  void addResiduoInteresse(Residuo);
  void addSolicitacao(Solicitacao);
  void addDoacao(Doacao);

  void imprimirResiduosInteresse();
};

#endif