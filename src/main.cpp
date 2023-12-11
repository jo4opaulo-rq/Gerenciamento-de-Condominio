#include <iostream>
#include <limits>

#include "login.hpp"

using namespace std;

int main(){

    Administrador administrador;
    Porteiro porteiro;
    int opcao = 0;
    string funcao;

    cout << "------------------------------" << endl;
    cout << "------SISTEMA CONDOMINIO------\n" << endl;
    cout << "------------------------------" << endl;

    do{
        Login login;
        bool statusLogin;

        cout << "1- Entrar como porteiro" << endl;
        cout << "2- Entrar como administrador" << endl;
        cout << "3- Sair" << endl;
        opcao = login.lerInt(opcao, "Opção: ");

        switch(opcao){
            case 1:
                funcao = "porteiro";
                statusLogin = login.fazerLogin(funcao);

                if(statusLogin == true){
                    login.telaPorteiro();
                }
                break;
            case 2:
                funcao = "administrador";
                statusLogin = login.fazerLogin(funcao);

                if(statusLogin == true){
                    login.telaAdministrador();
                }
                break;
            case 3:
                system("clear || cls");
                cout << "---Encerrando Sistema..." << endl;
                break;
            default:
                system("clear || cls");
                cout << "---Opção inválida! Digite um número entre 1 e 3---\n" << endl;
                break;
        }
    } while(opcao != 3);

    return 0;
}
