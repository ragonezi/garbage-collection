#include <iostream>
#include <stdlib.h>
int opcao;
std::string quantidade;
std::string novolocal;
int Tela1();
int Tela2();
int Tela3();
int Tela4();
int Tela5();
int TelaPrincipal();

int main(){
    TelaPrincipal();
    return 0;
}

int Tela1(){
    std::cout << "      SISTEMA DE GESTAO DE RESIDUOS\n\n";
    std::cout << "1.Cadastrar um residuo\n";
    std::cout << "0.Voltar\n";
    std::cout << "Digite a opcao desejada: ";
    std::cin >> opcao;
    switch(opcao){
        case 0:
            system("cls");
            TelaPrincipal();
        case 1:
            std::cout << "\n\n1.Solido";
            std::cout << "\n2.Liquido";
            std::cout << "\nDigite a opcao desejada: ";
            std::cin >> opcao;
            switch(opcao){
                case 1:

                    //Abre a lista de residuos solidos e o usuario deve escolher o que deseja

                case 2:

                    //Abre a lista de residuos liquidos e o usuario deve escolher o que deseja

                    std::cout << "";//(tirar isso depois)
                //default:
                //    system("cls");
                //    std::cout << "\nOpcao invalida\n\n";
                //    Tela1();
            }
            std::cout << "\n\nQuantidade: ";
            std::cin >> quantidade;
            std::cout << "\n\nModo adequado de armazenamento: ";

            //Colocar o modo adequado de armazenamento correspondente

            std::cout << "\n\n1.Confirmar o cadastro";
            std::cout << "\n2.Cancelar o cadastro";
            std::cout << "\nDigite a opcao desejada: ";
            std::cin >> opcao;
            switch(opcao){
                case 1:

                    //Confirmar o cadastro do residuo

                    system("cls");
                    std::cout << "Cadastro concluido!\n\n";
                    Tela1();
                case 2:
                    system("cls");
                    std::cout << "Cadastro cancelado\n\n";
                    Tela1();
                //default:
                //    system("cls");
                //    std::cout << "\nOpcao invalida\n\n";
                //    Tela1();
                }
        //default:
        //        system("cls");
        //        std::cout << "\nOpcao invalida\n\n"
        //        Tela1();
    }
    return 0;
}

int Tela2(){
    std::cout << "      SISTEMA DE GESTAO DE RESIDUOS";
    std::cout << "\n      LISTA DE RESIDUOS DISPONIVEIS";
    std::cout << "\n\nSelecione o residuo:\n1.Solido\n2.Liquido\nDigite a opcao desejada: ";
    std::cin >> opcao;
    switch(opcao){
        //default:
        //    system("cls");
        //    std::cout << "\nOpcao invalida\n\n";
        //    Tela2();
        case 1: //caso seja um residuo solido

            //abrir a lista de residuos solidos ate o usuario escolher o que deseja

            std::cout << "\n\n0.Voltar";

            //printar os residuos disponiveis

            std::cout << "\nDigite a opcao desejada: ";
            std::cin >> opcao;

            //printar nome, endereco, residuo e quantidade, dependendo da opcao escolhida OU retornar ao menu principal se for 0

            std::cout << "\n\nDeseja receber esse residuo:\n1.Sim\n2.Nao\nDigite a opcao desejada: ";
            std::cin >> opcao;
            switch(opcao){
                //default:
                //    system("cls");
                //    std::cout << "Opcao invalida\n\n";
                //    Tela2();
                case 1:
                    std::cout << "\n\nLocal de coleta:\n1.Endereco do doador\n2.Meu endereco\n3.Outro";
                    std::cout << "\nDigite a opcao desejada: ";
                    std::cin >> opcao;
                    switch(opcao){
                        //default:
                        //    system("cls");
                        //    std::cout << "Opcao invalida\n\n";
                        //    Tela2();
                        case 1:

                            //salvar os dados do agendamento

                            system("cls");
                            std::cout << "Agendamento concluido!\n\n";
                            Tela2();
                        case 2:

                            //salvar os dados do agendamento

                            system("cls");
                            std::cout << "Agendamento concluido!\n\n";
                            Tela2();
                        case 3:
                            std::cout << "\n\nNovo local: ";
                            std::cin >> novolocal;

                            //salvar os dados do agendamento

                            system("cls");
                            std::cout << "Agendamento concluido!\n\n";
                            Tela2();
                    }
                case 2:
                    system("cls");
                    std::cout << "Agendamento cancelado\n\n";
                    TelaPrincipal();
            }
        case 2: //caso seja um residuo liquido(mesmo codigo que o case 1, porém para residuo liquido

            //abrir a lista de residuos liquidos ate o usuario escolher o que deseja

            std::cout << "\n\n0.Voltar";

            //printar os residuos disponiveis

            std::cout << "\nDigite a opcao desejada: ";
            std::cin >> opcao;

            //printar nome, endereco, residuo e quantidade, dependendo da opcao escolhida OU voltar ao menu principal se for 0

            std::cout << "\n\nDeseja receber esse residuo:\n1.Sim\n2.Nao\nDigite a opcao desejada: ";
            std::cin >> opcao;
            switch(opcao){
                //default:
                //    system("cls");
                //    std::cout << "Opcao invalida\n\n";
                //    Tela2();
                case 1:
                    std::cout << "\n\nLocal de coleta:\n1.Endereco do doador\n2.Meu endereco\n3.Outro";
                    std::cout << "\nDigite a opcao desejada: ";
                    std::cin >> opcao;
                    switch(opcao){
                        //default:
                        //    system("cls");
                        //    std::cout << "Opcao invalida\n\n";
                        //    Tela2();
                        case 1:

                            //salvar os dados do agendamento

                            system("cls");
                            std::cout << "Agendamento concluido!\n\n";
                            Tela2();
                        case 2:

                            //salvar os dados do agendamento

                            system("cls");
                            std::cout << "Agendamento concluido!\n\n";
                            Tela2();
                        case 3:
                            std::cout << "\n\nNovo local: ";
                            std::cin >> novolocal;

                            //salvar os dados do agendamento

                            system("cls");
                            std::cout << "Agendamento concluido!\n\n";
                    }
                case 2:
                    system("cls");
                    std::cout << "Agendamento cancelado\n\n";
                    TelaPrincipal();
            }
    }
    return 0;
}


int Tela3(){
    std::cout << "      SISTEMA DE GESTAO DE RESIDUOS";
    std::cout <<"\n         RESIDUOS QUE CADASTREI";
    std::cout << "\n\n0.Voltar";

    //completar essa parte depois com os dados

    std::cout << "\nDigite a opcao desejada: ";
    std::cin >> opcao;

    //printar residuo e quantidade dependendo da opcao OU voltar para o menu principal

    std::cout << "\n\n1.Excluir esse residuo\n0.Voltar\nDigite a opcao desejada: ";
    std::cin >> opcao;
    switch(opcao){
        //default:
        //    system("cls");
        //    std::cout << "Opcao invalida\n\n";
        //    Tela3();
        case 0:
            system("cls");
            TelaPrincipal();
        case 1:

            //excluir o residuo

            system("cls");
            std::cout << "Residuo excluido!\n\n";
            TelaPrincipal();
    }
    return 0;
}

int Tela4(){
    std::cout << "      SISTEMA DE GESTAO DE RESIDUOS";
    std::cout << "\n              SOLICITACOES";
    std::cout << "\n\n0.Voltar";

    //completar depois:printar os residuos e se a opcao for 0, voltar para o menu principal

    std::cout << "\nDigite a opcao desejada: ";
    std::cin >> opcao;

    //completar depois:printar os dados sobre o residuo

    std::cout << "\n\n0.Voltar";//se o usuario for receptor, colocar tambem a opcao "Coleta realizada"
    std::cout << "\nDigite a opcao desejada: ";
    std::cin >> opcao;

    //completar depois:se for 0,voltar ao menu principal,se for 1(receptor),printar "Solicitacao atualizada"(por exemplo) e voltar

    system("cls");
    TelaPrincipal();
    return 0;
}

int Tela5(){
    std::cout << "      SISTEMA DE GESTAO DE RESIDUOS";
    std::cout << "\n          RANKING DE DOADORES";

    //printar os doadores na ordem do ranking

    std::cout << "\n\n0.Voltar\nDigite a opcao desejada: ";
    std::cin >> opcao;

    //printar uma mensagem caso seja uma opcao invalida

    system("cls");
    TelaPrincipal();
    return 0;
}

int TelaPrincipal(){
    std::cout << "      SISTEMA DE GESTAO DE RESIDUOS\n\n";
    std::cout << "1.Cadastrar residuo para doacao\n";
    std::cout << "2.Lista de residuos disponiveis\n";
    std::cout << "3.Residuos que cadastrei\n";
    std::cout << "4.Solicitacoes\n";
    std::cout << "5.Ranking de doadores\n";
    std::cout << "0.Sair\n";
    std::cout << "Digite a opcao desejada: ";
    std::cin >> opcao;
    switch(opcao){
        case 0:

            //deslogar o usuario

            return 0;
        case 1:
            system("cls");
            Tela1();
        case 2:
            system("cls");
            Tela2();
        case 3:
            system("cls");
            Tela3();
        case 4:
            system("cls");
            Tela4();
        case 5:
            system("cls");
            Tela5();
        //default: (o default seria no caso do usuário digitar alguma opcao invalida)
        //    system("cls");
        //    std::cout << "\nOpcao invalida\n\n"
        //    TelaPrincipal();
    }
    return 0;
}
