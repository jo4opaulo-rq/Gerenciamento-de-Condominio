#include <iostream>
#include <limits>

#include "login.hpp"

using namespace std;

int main(){

    Administrador administrador;
    Porteiro porteiro;
    int opcao = 0;
    string funcao;

    administrador.lerArquivo("archives/residentes");
    administrador.lerArquivo("archives/segurancas");
    administrador.lerArquivo("archives/zeladores");

    porteiro.lerArquivo("archives/visitantes");
    porteiro.lerArquivo("archives/encomendas");

    cout << "---------------------------" << endl;
    cout << "----------SISTEMA----------" << endl;
    cout << "---------------------------" << endl;

    while(true){
        Login login;
        bool statusLogin;

        cout << "1- Entrar como porteiro" << endl;
        cout << "2- Entrar como administrador" << endl;
        cout << "3- Sair" << endl;
        cout << "Opção: ";

        try{
            cin >> opcao;
            if(cin.fail()){
                throw runtime_error("---Erro: Digite um número inteiro!---\n");
            }
        } catch(runtime_error &e){
            system("clear || cls");
            cout << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

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
                return 0;
            default:
                system("clear || cls");
                cout << "---Opção inválida! Digite um número entre 1 e 3---\n" << endl;
                break;
        }
    }

    return 0;
}
