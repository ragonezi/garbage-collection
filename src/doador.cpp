#include "../includes/doador.h"

Doador::Doador() {}

Doador::Doador(std::string nome, std::string documento, std::string telefone, std::string endereco) : Pessoa::Pessoa(nome, documento, telefone, endereco)
{
}