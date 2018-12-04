#include "../includes/telas.h"

void Telas::telaInicial()
{
    int opcao = 0;
    bool opcaoIncorreta;
    std::cout << "SISTEMA DE GESTÃO DE RESIDUOS" << std::endl;
    std::cout << "1.Login" << std::endl;
    std::cout << "2.Cadastro" << std::endl;
    std::cout << "Digite a opcao desejada: ";
    opcao = Telas::getOpcao(1, 2);
    if (opcao == 1)
    {
        Telas::login();
    }
    else
    {
        Telas::cadastro();
    }
}

Usuario &Telas::login()
{
    std::string documento, senha;
    std::cout << "\nDigite o documento: ";
    std::cin >> documento;
    std::cin.ignore();
    std::cout << "\nDigite a senha: ";
    std::getline(std::cin, senha);
    // Funcao para buscar o registro no banco
    Usuario *usuario = new Usuario("Teste", documento, senha, "Teste");
    Telas::menuPrincipal(*usuario);
}

Usuario &Telas::cadastro()
{
    std::string nome, documento, telefone, endereco, senha, confirmacaoSenha;
    bool senhaIncorreta;

    std::cout << "\nDigite seu nome: ";
    std::getline(std::cin, nome);

    std::cout << "\nDigite o documento (CPF): ";
    std::cin >> documento;
    std::cin.ignore();

    std::cout << "\nDigite o telefone: ";
    std::getline(std::cin, telefone);

    std::cout << "\nDigite o endereco: ";
    std::getline(std::cin, endereco);
    do
    {
        std::cout << "\nDigite sua senha: ";
        std::getline(std::cin, senha);
        std::cout << "\nConfirme sua senha: ";
        std::getline(std::cin, confirmacaoSenha);
        if (senha != confirmacaoSenha)
        {
            senhaIncorreta = true;
            std::cout << "\nA senha e a confirmacao estao diferentes!";
        }
        else
        {
            senhaIncorreta = false;
        }
    } while (senhaIncorreta);
    Usuario *usuario = new Usuario(nome, documento, senha, endereco);
    // Funcao para cadastrar o usuario no banco
    Telas::menuPrincipal(*usuario);
}

void Telas::menuPrincipal(Usuario &usuario)
{
    int opcao;
    bool opcaoIncorreta;
    Telas::limparTela();
    Telas::cabecalho();
    std::cout << "1.Cadastrar residuo para doacao" << std::endl;
    std::cout << "2.Lista de residuos disponiveis" << std::endl;
    std::cout << "3.Residuos que cadastrei" << std::endl;
    std::cout << "4.Solicitacoes" << std::endl;
    std::cout << "5.Ranking de doadores" << std::endl;
    std::cout << "0.Sair" << std::endl;
    std::cout << "Digite a opcao desejada: ";
    opcao = Telas::getOpcao(0, 5);
    switch (opcao)
    {
    case 1:
        Telas::cadastrarResiduo(usuario);
        break;
    case 2:
        // do something
        break;
    case 3:
        // do something
        break;
    case 4:
        // do something
        break;
    case 5:
        // do something
        break;
    case 0:
        Telas::logout(usuario);
        break;
    }
}

void Telas::cadastrarResiduo(Usuario &usuario)
{
    Telas::cabecalho();
    std::cout << "1.Cadastrar um residuo" << std::endl;
    std::cout << "0.Voltar" << std::endl;
    std::cout << "Digite a opcao desejada: ";
    int opcao = Telas::getOpcao(0, 1);
    if (opcao == 0)
    {
        Telas::menuPrincipal(usuario);
    }
    else
    {
        std::cout << "1.Residuo Solido" << std::endl;
        std::cout << "2.Residuo Liquido" << std::endl;
        std::cout << "Digite a opcao desejada: ";
        opcao = Telas::getOpcao(1, 2);
        Residuo residuo = Telas::escolherResiduo(opcao);
        std::cout << "Digite a quantidade: ";
        int quantidade = Telas::getNumeroPositivo();
        Doador *doador = new Doador(usuario.getNome(), usuario.getDocumento(), usuario.getTelefone(), usuario.getEndereco());
        Doacao doacao = Doacao(residuo, *doador, quantidade, 1);
        std::cout << "Nome: " << doacao.getResiduo().getNome() << ", Quantidade: " << doacao.getQuantidade() << std::endl;
        std::cout << "1.Confirmar o cadastro" << std::endl;
        std::cout << "2.Cancelar o cadastro" << std::endl;
        std::cout << "Digite a opcao desejada: ";
        opcao = Telas::getOpcao(1, 2);
        if (opcao == 1)
        {
            std::cout << "Cadastro concluido!";
        }
        else
        {
            std::cout << "Cadastro cancelado!";
        }
        Telas::voltarMenuPrincipal(usuario);
    }
}

Residuo Telas::escolherResiduo(int tipoResiduo)
{
    // Temporario
    Residuo r1 = Residuo("Pilha", "Local seco com temperatura amena", 1);
    Residuo r2 = Residuo("Lampada", "Local seco com temperatura amena em recipiente coberto", 1);
    Residuo r3 = Residuo("Detergente", "Local seco com temperatura amena em recipiente coberto", 2);
    Residuo r4 = Residuo("Cloro", "Local seco com temperatura amena em recipiente coberto", 2);
    std::vector<Residuo> residuosSolidos;
    std::vector<Residuo> residuosLiquidos;
    residuosSolidos.push_back(r1);
    residuosSolidos.push_back(r2);
    residuosLiquidos.push_back(r3);
    residuosLiquidos.push_back(r4);
    std::vector<Residuo> residuos = tipoResiduo == 1 ? residuosSolidos : residuosLiquidos;
    int i = 0;
    for (std::vector<Residuo>::iterator it = residuos.begin(); it != residuos.end(); ++it)
    {
        i++;
        std::cout << i << "." << it->getNome() << std::endl;
    }
    std::cout << "Digite o numero do residuo: ";
    int opcao = Telas::getOpcao(1, i);
    return residuos[opcao - 1];
}

void Telas::logout(Usuario &usuario)
{
    delete &usuario;
}

void Telas::voltarMenuPrincipal(Usuario &usuario)
{
    system(PAUSE);
    Telas::menuPrincipal(usuario);
}

void Telas::cabecalho()
{
    std::cout << "SISTEMA DE GESTAO DE RESIDUOS\n"
              << std::endl;
}

void Telas::limparTela()
{
    system(CLRSCR);
}

int Telas::getOpcao(int primeira, int ultima)
{
    int opcao;
    bool opcaoIncorreta;
    do
    {
        opcaoIncorreta = !Telas::numero(opcao) || !(opcao >= primeira && opcao <= ultima);
        if (opcaoIncorreta)
        {
            std::cout << "\nOpcao incorreta! Digite novamente: ";
        }
    } while (opcaoIncorreta);
    return opcao;
}

int Telas::getNumeroPositivo()
{
    int numero;
    bool opcaoIncorreta;
    do
    {
        opcaoIncorreta = !Telas::numero(numero) || numero < 0;
        if (opcaoIncorreta)
        {
            std::cout << "\nOpcao incorreta! Digite novamente: ";
        }
    } while (opcaoIncorreta);
    return numero;
}

int Telas::getNumero()
{
    int numero;
    bool opcaoIncorreta;
    do
    {
        opcaoIncorreta = !Telas::numero(numero);
        if (opcaoIncorreta)
        {
            std::cout << "\nOpcao incorreta! Digite novamente: ";
        }
    } while (opcaoIncorreta);
    return numero;
}

int Telas::numero(int &opcao)
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