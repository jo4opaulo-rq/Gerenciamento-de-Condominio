#include <iostream>
// #include "pessoa.hpp"
#include "porteiros.hpp"
#include "residentes.hpp"

using namespace std;

int main(){

    //Residentes(string nome, string cpf, string dataNascimento, int predio, int apartamento, int andar, int vagaGaragem, string dataEntrada, string dataSaida, string telefone, string email):Pessoa(nome, cpf, dataNascimento
    Residentes r1("Joao", "123456789-10", "01/01/2000", 1, 1, 1, 1, "01/01/2020", "01/01/2021", "99999-9999", "ze@gmail.com");

    cout << "Residente N°1: " << endl;
    cout << "Nome: " << r1.getNome() << endl;
    cout << "CPF: " << r1.getCpf() << endl;
    cout << "Data de Nascimento: " << r1.getDataNascimento() << endl;
    cout << "Predio: " << r1.getPredio() << endl;
    cout << "Apartamento: " << r1.getApartamento() << endl;
    cout << "Andar: " << r1.getAndar() << endl;
    cout << "Vaga de Garagem: " << r1.getVagaGaragem() << endl;
    cout << "Data de Entrada: " << r1.getDataEntrada() << endl;
    cout << "Data de Saida: " << r1.getDataSaida() << endl;
    cout << "Telefone: " << r1.getTelefone() << endl;
    cout << "Email: " << r1.getEmail() << endl;

    return 0;
}