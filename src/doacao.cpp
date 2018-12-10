#include "../includes/doacao.h"

Doacao::Doacao() {}

Doacao::Doacao(Residuo residuo, Doador doador, std::string quantidade, unsigned int disponibilidade)
{
    this->setResiduo(residuo);
    this->setDoador(doador);
    this->setQuantidade(quantidade);
    this->setDisponibilidade(disponibilidade);
}

void Doacao::setResiduo(Residuo residuo)
{
    this->residuo = residuo;
}

void Doacao::setDoador(Doador doador)
{
    this->doador = doador;
}

void Doacao::setQuantidade(std::string quantidade)
{
    this->quantidade = quantidade;
}

void Doacao::setDisponibilidade(unsigned int disponibilidade)
{
    this->disponibilidade = disponibilidade;
}

void Doacao::setIdDoacao(std::string idDoacao)
{
    this->idDoacao = idDoacao;
}

Residuo Doacao::getResiduo()
{
    return this->residuo;
}

Doador Doacao::getDoador()
{
    return this->doador;
}

std::string Doacao::getQuantidade()
{
    return this->quantidade;
}

int Doacao::getDisponibilidade()
{
    return this->disponibilidade;
}

std::string Doacao::getIdDoacao()
{
    return this->idDoacao;
}