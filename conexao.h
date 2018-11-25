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
    const char *usuarioBanco = "root";
    const char *senhaBanco = "teste";

  public:
    Conexao();
    MYSQL getConexao();
    void abrirConexao();
    void fecharConexao();
};

#endif