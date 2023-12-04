#include <iostream>
// #include "pessoa.hpp"
#include "porteiros.hpp"


using namespace std;

int main(){
    Porteiros p1("Seu Zé", "123.456.789-10", "01/01/1999", "202000098376", "Porteiro", 40, "Portaria 1", "Noturno");

    cout << "Nome: " << p1.getNome() << endl;
    cout << "CPF: " << p1.getCpf() << endl;
    cout << "Data de Nascimento: " << p1.getDataNascimento() << endl;
    cout << "Matrícula: " << p1.getMatricula() << endl;
    cout << "Função: " << p1.getFuncao() << endl;
    cout << "Carga Horária: " << p1.getCargaHoraria() << endl;
    cout << "Portaria: " << p1.getPortaria() << endl;
    cout << "Turno: " << p1.getTurno() << endl;

    return 0;
}