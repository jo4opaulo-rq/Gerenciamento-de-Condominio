#include <iostream>
#include <vector>
#include <fstream>

#include "administrador.hpp"

using namespace std;

void Administrador::menuAdministrador(){
    cout << "1- Cadastrar Residente" << endl;
    cout << "2- Cadastrar Funcionário" << endl;
    cout << "3- Listar Residentes" << endl;
    cout << "4- Listar Funcionários" << endl;
    cout << "5- Remover Residente" << endl;
    cout << "6- Remover Funcionário" << endl;
    cout << "7- Buscar Residente" << endl;
    cout << "8- Buscar Funcionário" << endl;
    cout << "9- Sair" << endl;
    cout << "Opção: ";
}