#include "../includes/usuario.h"

Usuario::Usuario() {}

Usuario::Usuario(std::string nome, std::string documento, std::string telefone, std::string endereco) : Pessoa::Pessoa(nome, documento, telefone, endereco)
{
}

Usuario::Usuario(std::string nome, std::string documento, std::string telefone, std::string endereco, std::vector<Residuo> residuosInteresse) : Usuario::Usuario(nome, documento, telefone, endereco)
{
    this->setResiduosInteresse(residuosInteresse);
}

Usuario::Usuario(std::string nome, std::string documento, std::string telefone, std::string endereco, std::vector<Residuo> residuosInteresse, std::vector<Doacao> doacoes, std::vector<Solicitacao> solicitacoes) : Usuario::Usuario(nome, documento, telefone, endereco, residuosInteresse)
{
    this->setDoacoes(doacoes);
    this->setSolicitacoes(solicitacoes);
}

void Usuario::setResiduosInteresse(std::vector<Residuo> residuosInteresse)
{
    this->residuosInteresse = residuosInteresse;
}

void Usuario::setSolicitacoes(std::vector<Solicitacao> solicitacoes)
{
    this->solicitacoes = solicitacoes;
}

void Usuario::setDoacoes(std::vector<Doacao> doacoes)
{
    this->doacoes = doacoes;
}

std::vector<Residuo> &Usuario::getResiduosInteresse()
{
    return this->residuosInteresse;
}

std::vector<Doacao> Usuario::getDoacoes()
{
    return this->doacoes;
}

std::vector<Solicitacao> Usuario::getSolicitacoes()
{
    return this->solicitacoes;
}

void Usuario::addDoacao(Doacao doacao)
{
    this->doacoes.push_back(doacao);
}

void Usuario::addSolicitacao(Solicitacao solicitacao)
{
    this->solicitacoes.push_back(solicitacao);
}

void Usuario::addResiduoInteresse(Residuo residuoInteresse)
{
    this->residuosInteresse.push_back(residuoInteresse);
}

void Usuario::imprimirResiduosInteresse()
{
    for (std::vector<Residuo>::iterator i = this->getResiduosInteresse().begin(); i != this->getResiduosInteresse().end(); ++i)
    {
        std::cout << i->getNome() << std::endl;
        std::cout << i->getTipo() << std::endl;
        std::cout << i->getArmazenamento() << std::endl;
    }
}