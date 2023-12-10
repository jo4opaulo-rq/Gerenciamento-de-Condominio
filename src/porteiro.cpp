#include <iostream>
#include <vector>
#include <fstream>
#include "porteiro.hpp"


using namespace std;

void Porteiro::menuPorteiro(){
    cout << "1- Cadastrar visitante" << endl;
    cout << "2- Cadastrar encomenda" << endl;
    cout << "3- Listar residentes" << endl;
    cout << "4- Listar encomendas" << endl;
    cout << "5- Remover residente" << endl;
    cout << "6- Remover encomenda" << endl;
    cout << "7- Buscar residentes" << endl;
    cout << "8- Buscar encomendas" << endl;
    cout << "Opção: ";
}


void Porteiro::lerArquivo(string nomeArquivo){
    string nomeRemetente, nomeDestinatario,cpfDestinatario, numeroApartamento, dataRecebimento;
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
    
    for(int i = 0; i < linhas.size(); i+=6){
        nomeRemetente = linhas[i];
        nomeDestinatario = linhas[i+1];
        cpfDestinatario = linhas[i+2];
        numeroApartamento = linhas[i+3];
        dataRecebimento = linhas[i+4];

        Encomenda encomenda(nomeRemetente, nomeDestinatario, cpfDestinatario, numeroApartamento, dataRecebimento);
        encomendas.push_back(encomenda);

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

void Porteiro::buscarEncomenda(){
    string cpfDestinatario;

    cout << "Digite o CPF do destinatário: ";
    cin.ignore();
    getline(cin, cpfDestinatario);

    cout << "cpf: " << cpfDestinatario << endl;

    for(int i = 0; i < encomendas.size(); i++){
        if(encomendas[i].getCpfDestinatario() == cpfDestinatario){
            cout << "Nome do remetente: " << encomendas[i].getNomeRemetente() << endl;
            cout << "Nome do destinatário: " << encomendas[i].getNomeDestinatario() << endl;
            cout << "CPF do destinatário: " << encomendas[i].getCpfDestinatario() << endl;
            cout << "Número do apartamento: " << encomendas[i].getNumeroApartamento() << endl;
            cout << "Data de recebimento: " << encomendas[i].getDataRecebimento() << endl;
        }
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
    system(clear || cls);

    if(visitante.size() == 0){
        cout << "Não há visitantes cadastrados!" << endl;
    } else{
        for(int i = 0; i < visitante.size(); i++){
            cout << "-----Lista de visitantes-----" << endl;
            cout << "Nome do visitante: " << visitante[i].getNomeVisitante() << endl;
            cout << "Nome do visitado: " << visitante[i].getNomeVisitado() << endl;
            cout << "Número do apartamento: " << visitante[i].getApartamento() << endl;
            cout << "Número do andar: " << visitante[i].getAndar() << endl;
            cout << "Data da visita: " << visitante[i].getDataVisita() << endl;
            cout << "-----------------------------\n" << endl;
        }
    }
}