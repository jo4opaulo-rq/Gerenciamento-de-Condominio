#include <iostream>
#include <limits>

#include "administrador.hpp"
#include "porteiro.hpp"

using namespace std;

int main(){

    Administrador administrador;
    Porteiro porteiro;
    string login;
    int opcao = 0;

    administrador.lerArquivo("archives/residentes");
    administrador.lerArquivo("archives/segurancas");
    administrador.lerArquivo("archives/zeladores");

    porteiro.lerArquivo("archives/visitantes");
    porteiro.lerArquivo("archives/encomendas");

    cout << "---------------------------" << endl;
    cout << "----------SISTEMA----------" << endl;
    cout << "---------------------------" << endl;

    login = "porteiro";

    if(login == "porteiro"){
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
                    //porteiro.listarResidentes();
                    break;
                case 4:
                    //porteiro.listarEncomendas();
                    break;
                case 5:
                    //porteiro.removerResidente();
                    break;
                case 6:
                    //porteiro.removerEncomenda();
                    break;
                case 7:
                    //porteiro.buscarResidente();
                    break;
                case 8:
                    porteiro.buscarEncomenda();
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