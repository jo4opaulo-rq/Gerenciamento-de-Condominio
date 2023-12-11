#include <iostream>
#include <vector>
#include <fstream>
#include "porteiro.hpp"


using namespace std;

void Porteiro::menuPorteiro(){
    cout << "1- Cadastrar visitante" << endl;
    cout << "2- Cadastrar encomenda" << endl;
    cout << "3- Listar visitantes" << endl;
    cout << "4- Buscar encomenda" << endl;
    cout << "5- Buscar visitante por data" << endl;
    cout << "6- Sair" << endl;
    cout << "Opção: ";
}


void Porteiro::lerArquivo(string nomeArquivo){
    string nomeRemetente, nomeDestinatario,cpfDestinatario, numeroApartamento, dataRecebimento;
    string nomeVisitante, nomeVisitado, dataVisita;
    int apartamento, andar;
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

    if(nomeArquivo == "archives/visitantes"){
        for(int i = 0; i < linhas.size(); i+=6){
            nomeVisitante = linhas[i];
            nomeVisitado = linhas[i+1];
            apartamento  = stoi(linhas[i+2]);
            andar        = stoi(linhas[i+3]);
            dataVisita   = linhas[i+4];

            Visitante visitante(nomeVisitante, nomeVisitado, apartamento, andar, dataVisita);
            Visitantes.push_back(visitante);
        }
    } else if(nomeArquivo == "archives/encomendas"){
        for(int i = 0; i < linhas.size(); i+=6){
            nomeRemetente = linhas[i];
            nomeDestinatario = linhas[i+1];
            cpfDestinatario = linhas[i+2];
            numeroApartamento = linhas[i+3];
            dataRecebimento = linhas[i+4];

            Encomenda encomenda(nomeRemetente, nomeDestinatario, cpfDestinatario, numeroApartamento, dataRecebimento);
            encomendas.push_back(encomenda);
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
        arquivo << endl;
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
        arquivo << endl;
        arquivo.close();
    }
}

void Porteiro::listarVisitantes(){
    system("clear || cls");
    if(Visitantes.size() == 0){
        cout << "Não há visitantes cadastrados!" << endl;
    } else{
        cout << "       -----Lista de visitantes-----" << endl;
        for(int i = 0; i < Visitantes.size(); i++){
            cout << "Visitante Nº " << i + 1 << endl;
            cout << "Nome do visitante: " << Visitantes[i].getNomeVisitante() << endl;
            cout << "Nome do visitado: " << Visitantes[i].getNomeVisitado() << endl;
            cout << "Número do apartamento: " << Visitantes[i].getApartamento() << endl;
            cout << "Número do andar: " << Visitantes[i].getAndar() << endl;
            cout << "Data da visita: " << Visitantes[i].getDataVisita() << endl;
            cout << "---------------------------------\n" << endl;
        }
    }
}

void Porteiro::buscarEncomenda(){
    string cpfDestinatario;

    system("clear || cls");
    cout << "Digite o CPF do destinatário: ";
    cin.ignore();
    getline(cin, cpfDestinatario);

    if(encomendas.size() == 0){
        cout << "Não há encomendas cadastradas!" << endl;
    } else{
        for(int i = 0; i < encomendas.size(); i++){
            if(encomendas[i].getCpfDestinatario() == cpfDestinatario){
                cout << "---------------------------------" << endl;
                cout << "Nome do remetente: " << encomendas[i].getNomeRemetente() << endl;
                cout << "Nome do destinatário: " << encomendas[i].getNomeDestinatario() << endl;
                cout << "CPF do destinatário: " << encomendas[i].getCpfDestinatario() << endl;
                cout << "Número do apartamento: " << encomendas[i].getNumeroApartamento() << endl;
                cout << "Data de recebimento: " << encomendas[i].getDataRecebimento() << endl;
                cout << "---------------------------------\n" << endl;
            }
        }
    }
}

void Porteiro::buscarVisitanteData(){
    string buscarData;
    bool encontrou = false;

    system("clear || cls");
    cout << "Digite a data da visita: ";
    cin.ignore();
    getline(cin, buscarData);

    for(int i = 0; i < Visitantes.size(); i++){
        if(Visitantes[i].getDataVisita() == buscarData){
            cout << "---------------------------------" << endl;
            cout << "Nome do visitante: " << Visitantes[i].getNomeVisitante() << endl;
            cout << "Nome do visitado: " << Visitantes[i].getNomeVisitado() << endl;
            cout << "Número do apartamento: " << Visitantes[i].getApartamento() << endl;
            cout << "Número do andar: " << Visitantes[i].getAndar() << endl;
            cout << "Data da visita: " << Visitantes[i].getDataVisita() << endl;
            cout << "---------------------------------\n" << endl;
            encontrou = true;
        }
    }

    if(!encontrou){
        cout << "---Não há visitantes cadastrados nessa data!---\n" << endl;
    }
}