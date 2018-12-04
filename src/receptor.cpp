#include "../includes/receptor.h"

Receptor::Receptor() {}

Receptor::Receptor(std::string nome, std::string documento, std::string telefone, std::string endereco) : Pessoa::Pessoa(nome, documento, telefone, endereco)
{
}