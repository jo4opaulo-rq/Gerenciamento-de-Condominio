#include <iostream>
#include <limits>

#include "login.hpp"

using namespace std;

bool Login::fazerLogin(string funcao){
    string login, senha;
    int opcao;

    while(true){
        system("clear || cls");
        cout << "Login: ";
        cin >> login;
        cout << "Senha: ";
        cin >> senha;

        if(funcao == "porteiro"){
            if(login == loginPorteiro && senha == senhaPorteiro){
                system("clear || cls");
                return true;
            }
        } else if(funcao == "administrador"){
            if(login == loginAdministrador && senha == senhaAdministrador){
                system("clear || cls");
                return true;
            }
        }

        system("clear || cls");
        cout << "---Login ou senha incorretos!---\n" << endl;
        try{
            cout << "1- Tentar novamente" << endl;
            cout << "2- Voltar" << endl;
            cout << "Opção: ";
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

        if(opcao == 2){
            system("clear || cls");
            break;
        }
    }

    return false;
}

int Login::lerInt(int numero, std::string msg){
    bool flag = false;

    do{
        try{
            cout << msg;
            cin >> numero;
            if(cin.fail()){
                throw runtime_error("\n---Erro: Digite um número inteiro!---\n");
            } else{
                flag = true;
            }
        } catch(runtime_error &e){
            system("clear || cls");
            cout << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while(!flag);

    return numero;
}

void Login::telaAdministrador(){
    Administrador administrador;
    int opcao;

    administrador.lerArquivo("archives/residentes");
    administrador.lerArquivo("archives/segurancas");
    administrador.lerArquivo("archives/zeladores");

    do{
        administrador.menuAdministrador();
        opcao = lerInt(opcao, "Opção: ");

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

void Login::telaPorteiro(){
    Porteiro porteiro;
    int opcao;

    porteiro.lerArquivo("archives/visitantes");
    porteiro.lerArquivo("archives/encomendas");

    do{
            porteiro.menuPorteiro();
            opcao = lerInt(opcao, "Opção: ");

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
                    system("clear || cls");
                    porteiro.atualizarArquivo("archives/visitantes");
                    porteiro.atualizarArquivo("archives/encomendas");
                    break;
                default:
                    system("clear || cls");
                    cout << "---Opção inválida! Digite um número entre 1 e 6---\n" << endl;
                    break;
            }
        } while(opcao != 6);
}