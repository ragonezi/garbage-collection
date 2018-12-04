#include "../includes/doacao.h"

Doacao::Doacao() {}

Doacao::Doacao(Residuo residuo, Doador doador, int quantidade, unsigned int disponibilidade)
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

void Doacao::setQuantidade(int quantidade)
{
    this->quantidade = quantidade;
}

void Doacao::setDisponibilidade(unsigned int disponibilidade)
{
    this->disponibilidade = disponibilidade;
}

Residuo Doacao::getResiduo()
{
    return this->residuo;
}

Doador Doacao::getDoador()
{
    return this->doador;
}

int Doacao::getQuantidade()
{
    return this->quantidade;
}

int Doacao::getDisponibilidade()
{
    return this->disponibilidade;
}