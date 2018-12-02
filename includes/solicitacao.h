#ifndef SOLICITACAO_H
#define SOLICITACAO_H

#include <string>
#include "doacao.h"
#include "receptor.h"

class Solicitacao
{
private:
  Doacao doacao;
  Receptor receptor;
  std::string proposta;
  std::string resposta;
  unsigned int status;

public:
  Solicitacao();
  Solicitacao(Doacao, Receptor, unsigned int);
  Solicitacao(Doacao, Receptor, unsigned int, std::string);
  Solicitacao(Doacao, Receptor, unsigned int, std::string, std::string);

  void setDoacao(Doacao);
  void setReceptor(Receptor);
  void setStatus(unsigned int);
  void setProposta(std::string);
  void setResposta(std::string);

  Doacao getDoacao();
  Receptor getReceptor();
  std::string getProposta();
  std::string getResposta();
  int getStatus();
};

#endif