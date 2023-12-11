#include <iostream>
#include <limits>

#include "administrador.hpp"
#include "porteiro.hpp"
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
                break;
            case 2:
                funcao = "administrador";
                statusLogin = login.fazerLogin(funcao);
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
        if(statusLogin){
            break;
        }
    }

    if(funcao == "porteiro"){
        do{
            porteiro.menuPorteiro();
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
                    porteiro.cadastrarVisitante();
                    break;
                case 2:
                    porteiro.cadastrarEncomenda();
                    break;
                case 3:
                    porteiro.listarVisitantes();
                    break;
                case 4:
                    porteiro.buscarEncomenda();
                    break;
                case 5:
                    porteiro.buscarVisitanteData();
                    break;
                case 6:
                    break;
                case 7:
                    break;
                case 8:
                    break;
                case 9:
                    system("clear || cls");
                    cout << "---Encerrando Sistema..." << endl;
                    //porteiro.atualizarArquivo("archives/residentes");
                    //porteiro.atualizarArquivo("archives/encomendas");
                    break;
                default:
                    system("clear || cls");
                    cout << "---Opção inválida! Digite um número entre 1 e 9---\n" << endl;
                    break;
            }
        } while(opcao != 9);
    } else{
        do{
        administrador.menuAdministrador();
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
                administrador.cadastrarResidente();
                break;
            case 2:
                administrador.cadastrarFuncionario();
                break;
            case 3:
                administrador.listarResidentes();
                break;
            case 4:
                administrador.listarFuncionarios();
                break;
            case 5:
                administrador.removerResidente();
                break;
            case 6:
                administrador.removerFuncionario();
                break;
            case 7:
                administrador.buscarResidente();
                break;
            case 8:
                administrador.buscarFuncionario();
                break;
            case 9:
                system("clear || cls");
                cout << "---Encerrando Sistema..." << endl;
                administrador.atualizarArquivo("archives/residentes");
                administrador.atualizarArquivo("archives/segurancas");
                administrador.atualizarArquivo("archives/zeladores");
                break;
            default:
                system("clear || cls");
                cout << "---Opção inválida! Digite um número entre 1 e 9---\n" << endl;
                break;
        }
        } while(opcao != 9);
    }
    return 0;
}