#include "conexao.h"

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
    if (mysql_real_connect(&this->instanciaConexao, "localhost", this->usuarioBanco, this->senhaBanco, NULL, 0, NULL, 0) == NULL)
    {
        mysql_error(&this->instanciaConexao);
        throw "Database login error";
    }
}

MYSQL Conexao::getConexao()
{
    return this->instanciaConexao;
}

void Conexao::fecharConexao()
{
    mysql_close(&this->instanciaConexao);
}
