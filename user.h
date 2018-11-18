#ifndef user_h
#define user_h
#include <string>
#include <iostream>

class usuario{
protected:
	std::string nome;
	int CPF;
	std::string endereco;
	std::string telefone;
public:
	usuario();

	void set_nome();
	std::string get_nome();

	void set_CPF();
	int get_CPF();

	void set_endereco();
	std::string get_endereco();

	void set_telefone();
	std::string get_telefone();
};

usuario::usuario(void){
	std::cout << "User criado" << std::endl;
}

void usuario::set_nome(){
	std::string t;
	std::cout << "Digite um nome:" << std::endl;
	std::cin >> t;
	this->nome = t;
}
std::string usuario::get_nome(){
	return this->nome;

}
void usuario::set_CPF(){
	int r;
	std::cout << "Digite uma CPF:" << std::endl;
	std::cin >> r;
	this->CPF = r;
}
int usuario::get_CPF(){
	return this->CPF;
}

void usuario::set_endereco(){
	std::string e;
	std::cout << "Digite seu endereco:" << std::endl;
	std::cin >> e;
	this->endereco = e;
}
std::string usuario::get_endereco(){
	return this->endereco;
}

void usuario::set_telefone(){
	std::string t;
	std::cout << "Digite seu telefone:" << std::endl;
	std::cin >> t;
	this->telefone = t;
}
std::string usuario::get_telefone(){
	return this->telefone;
}

#endif