#include <iostream>

#include "administrador.hpp"
#include "porteiro.hpp"

using namespace std;

int main(){

    Administrador administrador;
    //Zelador zelador
    int opcao = 0;

    cout << "---------------------------" << endl;
    cout << "----------SISTEMA----------" << endl;
    cout << "---------------------------" << endl;

    //login

    do{
        administrador.menuAdministrador();
        cin >> opcao;

        switch(opcao){
            case 1:
                //cadastrar residente
                break;
            case 2:
                //cadastrar funcionario
                break;
            case 3:
                //listar residentes
                break;
            case 4:
                //listar funcionarios
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
                cout << "\nEncerrando Sistema..." << endl;
                break;
            default:
                cout << "Opção inválida!" << endl;
                break;
        }
    } while(opcao != 9);

    return 0;
}