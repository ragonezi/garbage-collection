#ifndef user_h
#define user_h
#include <string>
#include <iostream>

class usuario
{
  protected:
    std::string nome;
    int CPF;

  public:
    usuario();
    void set_nome();
    std::string get_nome();
    void set_CPF();
    int get_CPF();
};

usuario::usuario(void)
{
    std::cout << "User criado" << std::endl;
}

void usuario::set_nome()
{
    std::string t;
    std::cout << "Digite um nome:" << std::endl;
    std::cin >> t;
    this->nome = t;
}
std::string usuario::get_nome()
{
    return this->nome;
}
void usuario::set_CPF()
{
    int r;
    std::cout << "Digite uma CPF:" << std::endl;
    std::cin >> r;
    this->CPF = r;
}
int usuario::get_CPF()
{
    return this->CPF;
}

#endif
