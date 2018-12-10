#include "../includes/conexao.h"

Conexao::Conexao()
{
    if (mysql_init(&this->instanciaConexao) == NULL)
    {
        mysql_error(&this->instanciaConexao);
        throw "Connector error";
    }

    this->abrirConexao();
}

void Conexao::abrirConexao()
{
    if (mysql_real_connect(&this->instanciaConexao, this->host, this->usuarioBanco, this->senhaBanco, this->nomeBanco, this->porta, this->unixSocket, this->flag) == NULL)
    {
        mysql_error(&this->instanciaConexao);
        throw "Database login error";
    }
}

MYSQL &Conexao::getConexao()
{
    return this->instanciaConexao;
}

void Conexao::fecharConexao()
{
    mysql_close(&this->instanciaConexao);
}
