
#include "../includes/auxiliar.h"

int Auxiliar::confirmar()
{
    std::cout << " 1.Sim" << std::endl;
    std::cout << " 2.Nao" << std::endl;
    return Auxiliar::getOpcao(1, 2);
}

int Auxiliar::confirmarCadastro()
{
    std::cout << "\n 1.Confirmar o cadastro" << std::endl;
    std::cout << " 2.Cancelar o cadastro" << std::endl;
    return Auxiliar::getOpcao(1, 2);
}

int Auxiliar::confirmarSolicitacao()
{
    std::cout << " 1.Enviar solicitacao" << std::endl;
    std::cout << " 2.Cancelar coleta" << std::endl;
    return Auxiliar::getOpcao(1, 2);
}

void Auxiliar::pausarSistema()
{
    system(PAUSE);
}

void Auxiliar::limparTela()
{
    system(CLRSCR);
}

int Auxiliar::getOpcao(int primeira, int ultima)
{
    int opcao;
    bool opcaoIncorreta;
    std::cout << " Digite a opcao desejada: ";
    do
    {
        opcaoIncorreta = !Auxiliar::numero(opcao) || !(opcao >= primeira && opcao <= ultima);
        if (opcaoIncorreta)
        {
            std::cout << "\n Opcao invalida! Tente novamente: ";
        }
    } while (opcaoIncorreta);
    return opcao;
}

int Auxiliar::getNumeroPositivo()
{
    int numero;
    bool opcaoIncorreta;
    do
    {
        opcaoIncorreta = !Auxiliar::numero(numero) || numero < 0;
        if (opcaoIncorreta)
        {
            std::cout << "\n Opcao invalida! Tente novamente: ";
        }
    } while (opcaoIncorreta);
    return numero;
}

int Auxiliar::getNumero()
{
    int numero;
    bool opcaoIncorreta;
    do
    {
        opcaoIncorreta = !Auxiliar::numero(numero);
        if (opcaoIncorreta)
        {
            std::cout << "\n Opcao invalida! Tente novamente: ";
        }
    } while (opcaoIncorreta);
    return numero;
}

int Auxiliar::numero(int &opcao)
{
    std::string opcaoDigitada;
    std::cin >> opcaoDigitada;

    std::cin.ignore();

    std::istringstream ss(opcaoDigitada);
    int numero;
    ss >> numero;

    if (!ss.eof())
    {
        return false;
    }
    else
    {
        opcao = numero;
        return true;
    }
}

std::string Auxiliar::getDocumento()
{

    std::string input;
    int documento[14];
    bool opcaoIncorreta;
    do
    {
        std::getline(std::cin, input);

        for (int i = 0; i < input.length(); i++)
        {
            if (i >= 14)
                break;
            documento[i] = static_cast<int>(input[i] - 48);
        }
        if (input.length() == 11)
        {
            opcaoIncorreta = !Auxiliar::validaCPF(documento);
        }
        else if (input.length() == 14)
        {
            opcaoIncorreta = !Auxiliar::validaCNPJ(documento);
        }
        else
        {
            opcaoIncorreta = true;
            std::cout << "\n Documento invalido! Tente novamente: ";
        }
    } while (opcaoIncorreta);

    return input;
}

bool Auxiliar::validaCNPJ(const int *const cnpj)
{
    int digito1, digito2, aux = 0, test = 0;
    //Primeiro digito verificador
    for (char i = 0; i < 12; i++)
    {
        if (i < 4)
            aux += (cnpj[i] * (5 - i));
        else
            aux += (cnpj[i] * (13 - i));
    }
    if (aux == 0)
    {
        digito1 = 11;
    }
    else
    {
        aux %= 11;
        if (aux < 2)
            digito1 = 0;
        else
            digito1 = 11 - aux;
    }

    // Segundo digito verificador
    aux = 0;
    for (char i = 0; i < 13; i++)
    {
        if (i < 5)
            aux += (cnpj[i] * (6 - i));
        else
            aux += (cnpj[i] * (14 - i));
    }
    aux %= 11;
    if (aux < 2)
        digito2 = 0;
    else
        digito2 = 11 - aux;

    // Digitos Verificadores batem com o input?
    if (digito1 == cnpj[12] && digito2 == cnpj[13])
        return true;
    else
        return false;
}

bool Auxiliar::validaCPF(const int *const cpf)
{
    int digito1, digito2, temp = 0;
    // Primeiro digito verificador
    for (char i = 0; i < 9; i++)
        temp += (cpf[i] * (10 - i));
    if (temp == 0)
    {
        digito1 = 11;
    }
    else
    {
        temp %= 11;
        if (temp < 2)
            digito1 = 0;
        else
            digito1 = 11 - temp;
    }

    // Segundo digito verificador
    temp = 0;
    for (char i = 0; i < 10; i++)
        temp += (cpf[i] * (11 - i));
    temp %= 11;
    if (temp < 2)
        digito2 = 0;
    else
        digito2 = 11 - temp;

    // Digitos Verificadores batem com o input?
    if (digito1 == cpf[9] && digito2 == cpf[10])
        return true;
    else
        return false;
}