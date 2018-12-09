#include "../includes/telas.h"

// Temporario

std::vector<Residuo> rSolidos()
{
    std::vector<Residuo> residuosSolidos;
    Residuo r1 = Residuo("Pilha", "Local seco com temperatura amena", 1);
    Residuo r2 = Residuo("Lampada", "Local seco com temperatura amena em recipiente coberto", 1);
    residuosSolidos.push_back(r1);
    residuosSolidos.push_back(r2);
    return residuosSolidos;
}

std::vector<Residuo> rLiquidos()
{
    std::vector<Residuo> residuosLiquidos;
    Residuo r3 = Residuo("Detergente", "Local seco com temperatura amena em recipiente coberto", 2);
    Residuo r4 = Residuo("Cloro", "Local seco com temperatura amena em recipiente coberto", 2);
    residuosLiquidos.push_back(r3);
    residuosLiquidos.push_back(r4);
    return residuosLiquidos;
}

std::vector<Doacao> dSolidos()
{
    std::vector<Doacao> doacoesResiduosSolidos;
    Doador *doador1 = new Doador("Teste", "1000", "10", "10");
    Residuo r1 = Residuo("Pilha", "Local seco com temperatura amena", 1);
    Residuo r2 = Residuo("Lampada", "Local seco com temperatura amena em recipiente coberto", 1);
    Doacao d1 = Doacao(r1, *doador1, "10 unidades", 0);
    Doacao d2 = Doacao(r2, *doador1, "20 unidades", 0);
    doacoesResiduosSolidos.push_back(d1);
    doacoesResiduosSolidos.push_back(d2);
    return doacoesResiduosSolidos;
}

std::vector<Doacao> dLiquidos()
{
    std::vector<Doacao> doacoesResiduosLiquidos;
    Doador *doador1 = new Doador("Teste", "1000", "10", "10");
    Residuo r3 = Residuo("Detergente", "Local seco com temperatura amena em recipiente coberto", 2);
    Residuo r4 = Residuo("Cloro", "Local seco com temperatura amena em recipiente coberto", 2);
    Doacao d3 = Doacao(r3, *doador1, "10 baldes", 0);
    Doacao d4 = Doacao(r4, *doador1, "20 baldes", 0);
    doacoesResiduosLiquidos.push_back(d3);
    doacoesResiduosLiquidos.push_back(d4);
    return doacoesResiduosLiquidos;
}

std::vector<Doador> rDoadores()
{
    Doador d1 = Doador("Doador 1", "1000", "10", "10");
    Doador d2 = Doador("Doador 2", "1000", "10", "10");
    Doador d3 = Doador("Doador 3", "1000", "10", "10");
    std::vector<Doador> doadores;
    doadores.push_back(d1);
    doadores.push_back(d2);
    doadores.push_back(d3);
    return doadores;
}

// Fim temporario

void Telas::telaInicial()
{
    int opcao = 0;
    bool opcaoIncorreta;
    Telas::cabecalho();
    std::cout << " 1.Login" << std::endl;
    std::cout << " 2.Cadastro" << std::endl;
    opcao = Auxiliar::getOpcao(1, 2);
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
    Telas::cabecalho();
    std::cout << "                 LOGIN" << std::endl
              << std::endl;
    std::string documento, senha;
    std::cout << " CPF/CPNJ: ";
    documento = Auxiliar::getDocumento();
    std::cout << " Senha: ";
    std::getline(std::cin, senha);
    std::cout << std::endl;
    // ( FUNÇÃO PARA BUSCAR O REGISTRO NO BANCO E VALIDAR ENTRADA )
    Usuario *usuario = new Usuario("Teste", documento, senha, "Teste");
    Telas::menuPrincipal(*usuario);
}

Usuario &Telas::cadastro()
{
    Telas::cabecalho();
    std::cout << "                CADASTRO" << std::endl
              << std::endl;
    std::string nome, documento, telefone, endereco, senha, confirmacaoSenha;
    bool senhaIncorreta;

    std::cout << " CPF/CPNJ: ";
    documento = Auxiliar::getDocumento();
    std::cin.ignore();

    std::cout << " Nome: ";
    std::getline(std::cin, nome);

    std::cout << " Telefone: ";
    std::getline(std::cin, telefone);

    std::cout << " Endereco: ";
    std::getline(std::cin, endereco);
    do
    {
        std::cout << " Senha: ";
        std::getline(std::cin, senha);
        std::cout << " Confirmar Senha: ";
        std::getline(std::cin, confirmacaoSenha);
        if (senha != confirmacaoSenha)
        {
            senhaIncorreta = true;
            std::cout << "\n As senhas nao coincidem! Tente novamente \n\n";
        }
        else
        {
            senhaIncorreta = false;
        }
    } while (senhaIncorreta);
    Usuario *usuario = new Usuario(nome, documento, senha, endereco);
    // ( FUNCAO PARA CADASTRAR O USUARIO NO BANCO )
    Telas::menuPrincipal(*usuario);
}

void Telas::menuPrincipal(Usuario &usuario)
{
    int opcao;
    bool opcaoIncorreta;
    Telas::cabecalho();
    std::cout << " 1.Cadastrar residuo para doacao" << std::endl;
    std::cout << " 2.Lista de residuos disponiveis" << std::endl;
    std::cout << " 3.Residuos que cadastrei" << std::endl;
    std::cout << " 4.Solicitacoes" << std::endl;
    std::cout << " 5.Ranking de doadores" << std::endl;
    std::cout << " 0.Sair\n"
              << std::endl;
    opcao = Auxiliar::getOpcao(0, 5);
    switch (opcao)
    {
    case 1:
        Telas::cadastrarResiduo(usuario);
        break;
    case 2:
        Telas::cadastrarSolicitacao(usuario);
        break;
    case 3:
        Telas::doacoesCadastradas(usuario);
        break;
    case 4:
        Telas::listaSolicitacoes(usuario);
        break;
    case 5:
        Telas::rankingDoadores(usuario);
        break;
    case 0:
        Telas::logout(usuario);
        break;
    }
}

void Telas::cadastrarResiduo(Usuario &usuario)
{
    Telas::cabecalho();
    std::cout << " 1.Cadastrar um residuo" << std::endl;
    std::cout << " 0.Voltar" << std::endl;
    int opcao = Auxiliar::getOpcao(0, 1);
    if (opcao == 0)
    {
        Telas::menuPrincipal(usuario);
    }
    else
    {
        int tipoResiduo = Telas::escolherTipoResiduo();

        Residuo residuo = Telas::escolherResiduo(tipoResiduo);

        std::cout << "\n Digite a quantidade: ";
        std::string quantidade;
        std::getline(std::cin, quantidade);

        Doador *doador = new Doador(usuario.getNome(), usuario.getDocumento(), usuario.getTelefone(), usuario.getEndereco());
        Doacao doacao = Doacao(residuo, *doador, quantidade, 1);
        std::cout << "\n " << doacao.getResiduo().getNome() << ", " << doacao.getQuantidade() << std::endl;

        opcao = Auxiliar::confirmarCadastro();

        if (opcao == 1)
        {
            usuario.addDoacao(doacao);
            std::cout << " Cadastro concluido!" << std::endl;
            // Aqui os codigos do banco
        }
        else
        {
            std::cout << " Cadastro cancelado!" << std::endl;
        }
        Auxiliar::pausarSistema();
        Telas::menuPrincipal(usuario);
    }
}

int Telas::escolherTipoResiduo()
{
    std::cout << "\nSelecione o tipo do residuo:" << std::endl;
    std::cout << " 1.Solido" << std::endl;
    std::cout << " 2.Liquido" << std::endl;
    return Auxiliar::getOpcao(1, 2);
}

Residuo Telas::escolherResiduo(int tipoResiduo)
{

    std::vector<Residuo> residuos = tipoResiduo == 1 ? rSolidos() : rLiquidos();
    int i = 0;
    std::cout << std::endl;
    for (std::vector<Residuo>::iterator it = residuos.begin(); it != residuos.end(); ++it)
    {
        i++;
        std::cout << " " << i << "." << it->getNome() << std::endl;
    }
    int opcao = Auxiliar::getOpcao(1, i);
    return residuos[opcao - 1];
}

void Telas::cadastrarSolicitacao(Usuario &usuario)
{
    Telas::cabecalho();
    std::cout << "      LISTA DE RESIDUOS DISPONIVEIS" << std::endl;

    int tipoResiduo = Telas::escolherTipoResiduo();

    std::vector<Doacao> doacoesDisponiveis = (tipoResiduo == 1) ? dSolidos() : dLiquidos();

    int indiceDoacao = Telas::escolherDoacao(doacoesDisponiveis);

    if (indiceDoacao != -1)
    {
        Doacao doacaoSelecionada = doacoesDisponiveis[indiceDoacao];

        Telas::dadosDoacao(doacaoSelecionada);
        std::cout << std::endl;
        std::cout << "Deseja receber esse residuo?" << std::endl;
        int confirmacao = Auxiliar::confirmar();

        if (confirmacao == 1)
        {
            std::cout << "Local de coleta:" << std::endl;
            std::cout << " 1.Endereco do doador" << std::endl;
            std::cout << " 2.Meu endereco" << std::endl;
            std::cout << " 3.Outro";
            int opcaoEndereco = Auxiliar::getOpcao(1, 3);
            if (opcaoEndereco == 3)
            {
                std::cout << "\nNovo local: ";
                std::string enderecoEntrega;
                std::getline(std::cin, enderecoEntrega);
            }

            std::string dataEntrega;
            std::cout << "\nData para coleta: ";
            std::getline(std::cin, dataEntrega);

            confirmacao = Auxiliar::confirmarSolicitacao();
            if (confirmacao == 1)
            {
                Receptor receptor = Receptor(usuario.getNome(), usuario.getDocumento(), usuario.getTelefone(), usuario.getEndereco());
                Doacao *novaDoacao = new Doacao(doacaoSelecionada.getResiduo(), doacaoSelecionada.getDoador(), doacaoSelecionada.getQuantidade(), doacaoSelecionada.getDisponibilidade());
                Solicitacao novaSolicitacao = Solicitacao(*novaDoacao, receptor, 1);
                novaSolicitacao.setTipoEntrega(opcaoEndereco);
                novaSolicitacao.setDataEntrega(dataEntrega);
                usuario.addSolicitacao(novaSolicitacao);
                std::cout << "Solicitacao realizada com sucesso!" << std::endl;
            }
            else
            {
                std::cout << "Solicitacao cancelada!" << std::endl;
            }
            Auxiliar::pausarSistema();
        }
    }
    Telas::menuPrincipal(usuario);
}

void Telas::dadosDoacao(Doacao doacao)
{
    std::cout << doacao.getDoador().getNome() << std::endl;
    std::cout << doacao.getDoador().getEndereco() << std::endl;
    std::cout << doacao.getResiduo().getNome() << ", " << doacao.getQuantidade() << std::endl;
}

int Telas::escolherDoacao(std::vector<Doacao> doacoes)
{
    // A doacao deve ser de acordo com os residuos de interesse
    int i = 0;
    std::cout << std::endl;
    std::cout << " 0.Voltar" << std::endl;
    for (std::vector<Doacao>::iterator it = doacoes.begin(); it != doacoes.end(); ++it)
    {
        i++;
        std::cout << " " << i << "." << it->getResiduo().getNome();
        std::cout << ", " << it->getQuantidade();
        std::cout << ", " << it->getDoador().getEndereco() << std::endl;
    }
    int opcaoEscolhida = Auxiliar::getOpcao(0, i);
    if (opcaoEscolhida == 0)
    {
        return -1;
    }
    else
    {
        return (opcaoEscolhida - 1);
    }
}

void Telas::doacoesCadastradas(Usuario &usuario)
{
    Telas::cabecalho();
    std::cout << "\n        RESIDUOS QUE CADASTREI" << std::endl;
    int indiceDoacao = Telas::escolherDoacao(usuario.getDoacoes());

    if (indiceDoacao != -1)
    {
        std::cout << " " << usuario.getDoacoes()[indiceDoacao].getResiduo().getNome();
        std::cout << ", " << usuario.getDoacoes()[indiceDoacao].getQuantidade() << std::endl;

        std::cout << " 1.Excluir esta doacao" << std::endl;
        std::cout << " 0.Voltar" << std::endl;

        int opcao = Auxiliar::getOpcao(0, 1);

        if (opcao == 1)
        {
            usuario.removeDoacao(indiceDoacao);
            std::cout << "Doacao excluida com sucesso!" << std::endl;
            Auxiliar::pausarSistema();
        }
    }
    Telas::menuPrincipal(usuario);
}

void Telas::listaSolicitacoes(Usuario &usuario)
{
    Telas::cabecalho();
    std::cout << "      SOLICITACOES" << std::endl;

    std::cout << " 1.Minhas solicitacoes" << std::endl;
    std::cout << " 2.Solicitacoes recebidas" << std::endl;
    std::cout << " 0.Voltar" << std::endl;

    int opcaoEscolhida = Auxiliar::getOpcao(0, 2);

    if (opcaoEscolhida == 1)
    {
        std::vector<Doacao> doacoes;
        std::vector<Solicitacao> solicitacoes = usuario.getSolicitacoes();
        for (std::vector<Solicitacao>::iterator it = solicitacoes.begin(); it != solicitacoes.end(); ++it)
        {
            Doacao d1 = Doacao();
            doacoes.push_back(it->getDoacao());
        }
        int indiceSolicitacao = Telas::escolherDoacao(doacoes);

        if (indiceSolicitacao != -1)
        {
            Telas::dadosSolicitacao(usuario.getSolicitacoes()[indiceSolicitacao], true);

            std::cout << "0. Voltar" << std::endl;
            Auxiliar::getOpcao(0, 0);
        }
    }
    else if (opcaoEscolhida == 2)
    {
        // Buscar as solicitacoes das doacoes
        int indiceDoacao = Telas::escolherDoacao(usuario.getDoacoes());

        if (indiceDoacao != -1)
        {
            // Fazer consulta no banco e informar se existem solicitacoes

            Receptor *r1 = new Receptor("Teste", "1000", "10", "10");
            Solicitacao s1 = Solicitacao(usuario.getDoacoes()[indiceDoacao], *r1, 1, "Teste", "Teste");

            Telas::dadosSolicitacao(s1, false);
            std::cout << "0. Voltar" << std::endl;

            Auxiliar::getOpcao(0, 0);
        }
    }
    Telas::menuPrincipal(usuario);
}

void Telas::dadosSolicitacao(Solicitacao solicitacao, bool minhaSolicitacao)
{
    std::string nome, telefone;
    if (minhaSolicitacao)
    {
        nome = solicitacao.getDoacao().getDoador().getNome();
        telefone = solicitacao.getDoacao().getDoador().getTelefone();
    }
    else
    {
        nome = solicitacao.getReceptor().getNome();
        telefone = solicitacao.getReceptor().getTelefone();
    }
    std::cout << std::endl;
    std::cout << nome << std::endl;
    std::cout << solicitacao.getDoacao().getResiduo().getNome();
    std::cout << ", " << solicitacao.getDoacao().getQuantidade() << std::endl;
    std::cout << "Local: " << solicitacao.getDoacao().getDoador().getEndereco() << std::endl;
    std::cout << "Data: " << solicitacao.getDataEntrega() << std::endl;
    std::cout << "Telefone: " << telefone << std::endl;
}

void Telas::rankingDoadores(Usuario &usuario)
{
    Telas::cabecalho();
    std::cout << "      RANKING DE DOADORES" << std::endl;
    std::vector<Doador> doadores = rDoadores();
    for (std::vector<Doador>::iterator it = doadores.begin(); it != doadores.end(); ++it)
    {
        std::cout << it->getNome();
        std::cout << ", x doacoes" << std::endl;
    }

    Auxiliar::pausarSistema();
    Telas::menuPrincipal(usuario);
}

void Telas::logout(Usuario &usuario)
{
    delete &usuario;
}

void Telas::cabecalho()
{
    Auxiliar::limparTela();
    std::cout << " ---------------------------------------" << std::endl;
    std::cout << "      SISTEMA DE GESTAO DE RESIDUOS" << std::endl;
    std::cout << " ---------------------------------------" << std::endl;
}