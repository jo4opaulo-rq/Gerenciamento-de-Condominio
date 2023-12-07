#include <iostream>
// #include "pessoa.hpp"
#include "porteiros.hpp"
#include "residentes.hpp"
#include "zelador.hpp"

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


   Residentes r2("Maria", "123456789-10", "01/01/2000", 1, 1, 1, 1, "01/01/2020", "01/01/2021", "99999-9999", "maria@");
    cout << "Residente N°2: " << endl;
    cout << "Nome: " << r2.getNome() << endl;
    cout << "CPF: " << r2.getCpf() << endl;

    //Zelador(string nome, string cpf, string dataNascimento, string matricula, string funcao, string setor, float cargaHoraria, float salario, string turno);
    Zelador z1("Jose", "123456789-10", "01/01/2000", "00001", "Zelador", "Administrativo", 40, 1000, "Diurno");

    cout << "\n\nZelador N°1: " << endl;
    cout << "Nome: " << z1.getNome() << endl;
    cout << "CPF: " << z1.getCpf() << endl;
    cout << "Data de Nascimento: " << z1.getDataNascimento() << endl;
    cout << "Matricula: " << z1.getMatricula() << endl;
    cout << "Turno: " << z1.getTurno() << endl;
    cout << "Salario: " << z1.getSalario() << endl;

    return 0;
}