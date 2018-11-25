#ifndef CONEXAO_H
#define CONEXAO_H

#include <string>
#include <stdlib.h>
#include <iostream>
#include "mysql.h"

class Conexao
{
  private:
    MYSQL instanciaConexao;
    const char *host = "localhost";
    const char *usuarioBanco = "root";
    const char *senhaBanco = "teste";
    const char *nomeBanco = "trabalho_ps2";
    const int porta = 3306;
    const char *unixSocket = NULL;
    unsigned int flag = 0;

  public:
    Conexao();
    MYSQL getConexao();
    void abrirConexao();
    void fecharConexao();
};

#endif