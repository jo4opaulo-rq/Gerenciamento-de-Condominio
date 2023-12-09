#include <iostream>
#include "porteiro.hpp"

using namespace std;

Porteiro::Porteiro(){
    this->salario = 0.0;
    this->turno = "Manhã";
}

Porteiro::Porteiro(string nome, string cpf, string dataNascimento, string matricula, string funcao, string setor, float cargaHoraria, float salario, string turno, string portaria, string senha) : Funcionarios(matricula, funcao, setor, cargaHoraria, salario){
    this->salario = salario;
    this->turno = turno;
    this->portaria = portaria;
    this->senha = senha;
}

string Porteiro::getTurno(){
    return turno;
}

string Porteiro::getPortaria(){
    return portaria;
}

string Porteiro::getSenha(){
    return senha;
}

void Porteiro::setTurno(string turno){
    this->turno = turno;
}

void Porteiro::setPortaria(string portaria){
    this->portaria = portaria;
}

void Porteiro::setSenha(string senha){
    this->senha = senha;
}

void Porteiro::lerArquivo(string nomeArquivo){
    string nome, cpf, dataNascimento, dataEntrada, dataSaida, telefone, email, matricula, funcao, setor, turno;
    int predio, apartamento, andar, vagaGaragem;
    float cargaHoraria, salario;
    vector<string> linhas;
    fstream arquivo;

    arquivo.open(nomeArquivo + ".txt", ios::in | ios::app);

    if(arquivo.is_open()){
        string linha;

        while(getline(arquivo, linha)){
            linhas.push_back(linha);
        }

        arquivo.close();
    } else{
        cout << "Erro ao abrir o arquivo!" << endl;
    }

    for(int i = 0; i < linhas.size(); i+= 4){
        nome = linhas[i];
        cpf = linhas[i + 1];
        dataNascimento = linhas[i + 2];

        if(nomeArquivo == "archives/residentes"){
            predio = stoi(linhas[i + 3]);
            apartamento = stoi(linhas[i + 4]);
            andar = stoi(linhas[i + 5]);
            vagaGaragem = stoi(linhas[i + 6]);
            dataEntrada = linhas[i + 7];
            dataSaida = linhas[i + 8];
            telefone = linhas[i + 9];
            email = linhas[i + 10];

            Residentes novoResidente(nome, cpf, dataNascimento, predio, apartamento, andar, vagaGaragem, dataEntrada, dataSaida, telefone, email);
            residentes.push_back(novoResidente);

            i += 8;
}
    }
}


void Porteiro::buscarResidente(string cpf){

    bool residenteEncontrado = false;

    system("clear || cls");
    cout << "       ---Buscar Residente---" << endl;
    cout << "Digite o CPF do Residente (000.000.000-00): ";
    cin.ignore();
    getline(cin, cpf);

    for(int i = 0; i < residentes.size(); i++){
        if(residentes[i].getCpf() == cpf){
            cout << "-------Residente encontrado!-------" << endl;
            cout << "Nome: " << residentes[i].getNome() << endl;
            cout << "CPF: " << residentes[i].getCpf() << endl;
            cout << "Data de Nascimento: " << residentes[i].getDataNascimento() << endl;
            cout << "Número do Prédio: " << residentes[i].getPredio() << endl;
            cout << "Número do Apartamento: " << residentes[i].getApartamento() << endl;
            cout << "Número do Andar: " << residentes[i].getAndar() << endl;
            cout << "Número da Vaga de Garagem: " << residentes[i].getVagaGaragem() << endl;
            cout << "Data de Entrada: " << residentes[i].getDataEntrada() << endl;
            cout << "Data de Saída: " << residentes[i].getDataSaida() << endl;
            cout << "Telefone: " << residentes[i].getTelefone() << endl;
            cout << "E-mail: " << residentes[i].getEmail() << endl;
            cout << "-----------------------------------";
            cout << endl;
            residenteEncontrado = true;
            break;
        }
    }

    if(!residenteEncontrado){
        cout << "---Residente não encontrado!\n" << endl;
    }
}
