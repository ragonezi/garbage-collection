#include "../includes/solicitacao.h"

Solicitacao::Solicitacao() {}

Solicitacao::Solicitacao(Doacao doacao, Receptor receptor, unsigned int status)
{
    this->setDoacao(doacao);
    this->setReceptor(receptor);
    this->setStatus(status);
}

Solicitacao::Solicitacao(Doacao doacao, Receptor receptor, unsigned int status, std::string proposta) : Solicitacao::Solicitacao(doacao, receptor, status)
{
    this->setProposta(proposta);
}

Solicitacao::Solicitacao(Doacao doacao, Receptor receptor, unsigned int status, std::string proposta, std::string resposta) : Solicitacao::Solicitacao(doacao, receptor, status, proposta)
{
    this->setResposta(resposta);
}

void Solicitacao::setDoacao(Doacao doacao)
{
    this->doacao = doacao;
}

void Solicitacao::setReceptor(Receptor receptor)
{
    this->receptor = receptor;
}

void Solicitacao::setStatus(unsigned int status)
{
    this->status = status;
}

void Solicitacao::setProposta(std::string proposta)
{
    this->proposta = proposta;
}

void Solicitacao::setResposta(std::string resposta)
{
    this->resposta = resposta;
}

void Solicitacao::setDataEntrega(std::string dataEntrega)
{
    this->dataEntrega = dataEntrega;
}

void Solicitacao::setIdSolicitacao(std::string idSolicitacao)
{
    this->idSolicitacao = idSolicitacao;
}

void Solicitacao::setTipoEntrega(int tipoEntrega)
{
    this->tipoEntrega = tipoEntrega;
}

Doacao Solicitacao::getDoacao()
{
    return this->doacao;
}

Receptor Solicitacao::getReceptor()
{
    return this->receptor;
}

int Solicitacao::getStatus()
{
    return this->status;
}

std::string Solicitacao::getProposta()
{
    return this->proposta;
}

std::string Solicitacao::getResposta()
{
    return this->resposta;
}

std::string Solicitacao::getDataEntrega()
{
    return this->dataEntrega;
}

std::string Solicitacao::getIdSolicitacao()
{
    return this->idSolicitacao;
}

int Solicitacao::getTipoEntrega()
{
    return this->tipoEntrega;
}