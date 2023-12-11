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
            cout << "2- Sair" << endl;
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
            break;
        }
    }

    return false;
}