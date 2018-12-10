#include "../includes/pessoa.h"

Pessoa::Pessoa() {}

Pessoa::Pessoa(std::string nome, std::string documento, std::string telefone, std::string endereco)
{
    this->setNome(nome);
    this->setDocumento(documento);
    this->setTelefone(telefone);
    this->setEndereco(endereco);
}

void Pessoa::setNome(std::string nome)
{
    this->nome = nome;
}

void Pessoa::setDocumento(std::string documento)
{
    this->documento = documento;
}

void Pessoa::setTelefone(std::string telefone)
{
    this->telefone = telefone;
}

void Pessoa::setEndereco(std::string endereco)
{
    this->endereco = endereco;
}

void Pessoa::setIdPessoa(std::string idPessoa)
{
    this->idPessoa = idPessoa;
}

std::string Pessoa::getNome()
{
    return this->nome;
}

std::string Pessoa::getDocumento()
{
    return this->documento;
}

std::string Pessoa::getTelefone()
{
    return this->telefone;
}

std::string Pessoa::getEndereco()
{
    return this->endereco;
}

std::string Pessoa::getIdPessoa()
{
    return this->idPessoa;
}