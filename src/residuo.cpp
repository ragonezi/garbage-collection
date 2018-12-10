#include "../includes/residuo.h"

Residuo::Residuo() {}

Residuo::Residuo(std::string nome, std::string armazenamento, int tipo)
{
    this->setArmazenamento(armazenamento);
    this->setNome(nome);
    this->setTipo(tipo);
}

void Residuo::setArmazenamento(std::string armazenamento)
{
    this->armazenamento = armazenamento;
}

void Residuo::setNome(std::string nome)
{
    this->nome = nome;
}

void Residuo::setTipo(int tipo)
{
    this->tipo = tipo;
}

void Residuo::setIdResiduo(std::string idResiduo)
{
    this->idResiduo = idResiduo;
}

std::string Residuo::getArmazenamento()
{
    return this->armazenamento;
}

std::string Residuo::getNome()
{
    return this->nome;
}

int Residuo::getTipo()
{
    return this->tipo;
}

std::string Residuo::getIdResiduo()
{
    return this->idResiduo;
}