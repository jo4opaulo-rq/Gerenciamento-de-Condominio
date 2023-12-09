#include <iostream>
#include <limits>

#include "administrador.hpp"
#include "porteiro.hpp"

using namespace std;

int main(){

    Administrador administrador;
    //Zelador zelador
    int opcao = 0;

    administrador.lerArquivo("archives/residentes");
    administrador.lerArquivo("archives/segurancas");
    administrador.lerArquivo("archives/zeladores");

    cout << "---------------------------" << endl;
    cout << "----------SISTEMA----------" << endl;
    cout << "---------------------------" << endl;

    //login

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
                //remover residente
                break;
            case 6:
                //remover funcionario
                break;
            case 7:
                //buscar residente
                break;
            case 8:
                //buscar funcionario
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

    return 0;
}