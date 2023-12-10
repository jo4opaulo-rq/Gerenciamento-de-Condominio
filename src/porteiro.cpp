#include <iostream>
#include <vector>
#include <fstream>
#include "porteiro.hpp"


using namespace std;

<<<<<<< Updated upstream
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
=======
void Porteiro::menuPorteiro(){
    cout << "1- Cadastrar visitante" << endl;
    cout << "2- Cadastrar encomenda" << endl;
    cout << "3- Listar visitantes" << endl;
    cout << "4- Listar encomendas" << endl;
    cout << "5- Remover residente" << endl;
    cout << "6- Remover encomenda" << endl;
    cout << "7- Buscar residentes" << endl;
    cout << "8- Buscar encomendas" << endl;
    cout << "Opção: ";
>>>>>>> Stashed changes
}

void Porteiro::lerArquivo(string nomeArquivo){
    string nome, cpf, dataNascimento, dataEntrada, dataSaida, telefone, email, matricula, funcao, setor, turno;
    int predio, apartamento, andar, vagaGaragem;
    float cargaHoraria, salario;
<<<<<<< Updated upstream
=======
    string nomeRemetente, nomeDestinatario,cpfDestinatario, numeroApartamento, dataRecebimento;
>>>>>>> Stashed changes
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
    if(nomeArquivo == "archives/encomendas"){
        for(int i = 0; i < linhas.size(); i+=6){
            nomeRemetente = linhas[i];
            nomeDestinatario = linhas[i+1];
            cpfDestinatario = linhas[i+2];
            numeroApartamento = linhas[i+3];
            dataRecebimento = linhas[i+4];

<<<<<<< Updated upstream
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
=======
            Encomenda encomenda(nomeRemetente, nomeDestinatario, cpfDestinatario, numeroApartamento, dataRecebimento);
            encomendas.push_back(encomenda);
        }
>>>>>>> Stashed changes
    }
    /*for(int i = 0; i < linhas.size(); i+= 4){
        nome           = linhas[i];
        cpf            = linhas[i + 1];
        dataNascimento = linhas[i + 2];

        if(nomeArquivo == "archives/residentes"){
            predio      = stoi(linhas[i + 3]);
            apartamento = stoi(linhas[i + 4]);
            andar       = stoi(linhas[i + 5]);
            vagaGaragem = stoi(linhas[i + 6]);
            dataEntrada = linhas[i + 7];
            dataSaida   = linhas[i + 8];
            telefone    = linhas[i + 9];
            email       = linhas[i + 10];

            Residentes novoResidente(nome, cpf, dataNascimento, predio, apartamento, andar, vagaGaragem, dataEntrada, dataSaida, telefone, email);
            residente.push_back(novoResidente);

            i += 8;
        }
    }*/
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


void Porteiro::cadastrarEncomenda(){
    string nomeRemetente, nomeDestinatario, cpfDestinatario, numeroApartamento, dataRecebimento;
    cout << "Cadastro de encomenda" << endl;
    cout << "Nome do remetente: ";
    cin.ignore();
    getline(cin, nomeRemetente);
    cout << "Nome do destinatário: ";
    getline(cin, nomeDestinatario);
    cout << "CPF do destinatário: ";
    getline(cin, cpfDestinatario);
    cout << "Número do apartamento: ";
    getline(cin, numeroApartamento);
    cout << "Data de recebimento: ";
    getline(cin, dataRecebimento);
    cout << "Encomenda cadastrada com sucesso!" << endl;
    Encomenda encomenda(nomeRemetente, nomeDestinatario, cpfDestinatario, numeroApartamento, dataRecebimento);
    encomendas.push_back(encomenda);

    fstream arquivo;
    arquivo.open("archives/encomendas.txt", ios::out | ios::app);
    if(arquivo.is_open()){
        arquivo << nomeRemetente << endl;
        arquivo << nomeDestinatario << endl;
        arquivo << cpfDestinatario << endl;
        arquivo << numeroApartamento << endl;
        arquivo << dataRecebimento << endl;
        arquivo.close();
    }
    
}

void Porteiro::cadastrarVisitante(){
    string nomeVisitante, nomeVisitado, dataVisita;
    int apartamento, andar;
    cout << "Cadastro de visitante" << endl;
    cout << "Nome do visitante: ";
    cin.ignore();
    getline(cin, nomeVisitante);
    cout << "Nome do visitado: ";
    getline(cin, nomeVisitado);
    cout << "Número do apartamento: ";
    cin >> apartamento;
    cout << "Número do andar: ";
    cin >> andar;
    cin.ignore();
    cout << "Data da visita: ";
    getline(cin, dataVisita);

    cout << "Visitante cadastrado com sucesso!" << endl;
    Visitante visitante(nomeVisitante, nomeVisitado, apartamento, andar, dataVisita);
    Visitantes.push_back(visitante);

    fstream arquivo;
    arquivo.open("archives/visitantes.txt", ios::out | ios::app);
    if(arquivo.is_open()){
        arquivo << nomeVisitante << endl;
        arquivo << nomeVisitado << endl;
        arquivo << apartamento << endl;
        arquivo << andar << endl;
        arquivo << dataVisita << endl;
        arquivo.close();
    }
}

void Porteiro::listarVisitantes(){
    string nomeVisitante, nomeVisitado, dataVisita;
    int apartamento, andar;

    fstream arquivo;
    arquivo.open("archives/visitantes.txt", ios::in | ios::app);
    string linha;
    for(int i = 0; Visitantes.size(); i++){
        nomeVisitante = linha[i];
        nomeVisitado  = linha[i+1];
        apartamento   = (linha[i+2]);
        andar         = (linha[i+3]);
        dataVisita    = linha[i+4];

        Visitante visitante(nomeVisitante, nomeVisitado, apartamento, andar, dataVisita);
        Visitantes.push_back(visitante);
    }

    for(int i = 0; i < Visitantes.size(); i++){
        cout << "Nome do visitante: " << Visitantes[i].getNomeVisitante() << endl;
        cout << "Nome do visitado: " << Visitantes[i].getNomeVisitado() << endl;
        cout << "Número do apartamento: " << Visitantes[i].getApartamento() << endl;
        cout << "Número do andar: " << Visitantes[i].getAndar() << endl;
        cout << "Data da visita: " << Visitantes[i].getDataVisita() << endl;
    }
}