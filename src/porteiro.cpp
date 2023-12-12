#include <iostream>
#include <vector>
#include <fstream>
#include <limits>
#include "porteiro.hpp"


using namespace std;

void Porteiro::menuPorteiro(){
    cout << "1- Cadastrar visitante" << endl;
    cout << "2- Cadastrar encomenda" << endl;
    cout << "3- Listar visitantes" << endl;
    cout << "4- Buscar encomenda" << endl;
    cout << "5- Buscar visitante por data" << endl;
    cout << "6- Listar encomendas" << endl;
    cout << "7- Sair" << endl;
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

void Porteiro::atualizarArquivo(string nomeArquivo){
    fstream arquivo;
    arquivo.open(nomeArquivo + ".txt", ios::out | ios::trunc);

    if(arquivo.is_open()){
        if(nomeArquivo == "archives/visitantes"){
            for(int i = 0; i < Visitantes.size(); i++){
                arquivo << Visitantes[i].getNomeVisitante() << endl;
                arquivo << Visitantes[i].getNomeVisitado() << endl;
                arquivo << Visitantes[i].getApartamento() << endl;
                arquivo << Visitantes[i].getAndar() << endl;
                arquivo << Visitantes[i].getDataVisita() << endl;
                arquivo << endl;
            }
        } else if(nomeArquivo == "archives/encomendas"){
            for(int i = 0; i < encomendas.size(); i++){
                arquivo << encomendas[i].getNomeRemetente() << endl;
                arquivo << encomendas[i].getNomeDestinatario() << endl;
                arquivo << encomendas[i].getCpfDestinatario() << endl;
                arquivo << encomendas[i].getNumeroApartamento() << endl;
                arquivo << encomendas[i].getDataRecebimento() << endl;
                arquivo << endl;
            }
        }
        arquivo.close();
    } else{
        cout << "Erro ao abrir o arquivo!" << endl;
    }
}

int Porteiro::lerInt(int numero, std::string msg){
    bool flag = false;

    do{
        try{
            cout << msg;
            cin >> numero;
            if(cin.fail()){
                throw runtime_error("\n---Erro: Digite um número inteiro!---\n");
            } else{
                flag = true;
            }
        } catch(runtime_error &e){
            system("clear || cls");
            cout << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while(!flag);

    return numero;
}

void Porteiro::cadastrarEncomenda(){
    string nomeRemetente, nomeDestinatario, cpfDestinatario, numeroApartamento, dataRecebimento;

    system("clear || cls");
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

    system("clear || cls");
    cout << "---Encomenda cadastrada com sucesso!---\n" << endl;
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

    system("clear || cls");
    cout << "Cadastro de visitante" << endl;
    cout << "Nome do visitante: ";
    cin.ignore();
    getline(cin, nomeVisitante);
    cout << "Nome do visitado: ";
    getline(cin, nomeVisitado);
    apartamento = lerInt(apartamento, "Número do apartamento: ");
    andar = lerInt(andar, "Número do andar: ");
    cin.ignore();
    cout << "Data da visita: ";
    getline(cin, dataVisita);

    system("clear || cls");
    cout << "---Visitante cadastrado com sucesso!---\n" << endl;
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
        cout << "---Não há visitantes cadastrados!" << endl;
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
    bool encontrou = false;

    system("clear || cls");
    cout << "Digite o CPF do destinatário: ";
    cin.ignore();
    getline(cin, cpfDestinatario);

    if(encomendas.size() == 0){
        system("clear || cls");
        cout << "---Não há encomendas cadastradas!---\n" << endl;
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
                encontrou = true;
            }
        }
    }

    if(!encontrou){
        system("clear || cls");
        cout << "---Não há encomendas cadastradas para esse CPF!---\n" << endl;
    }
}

void Porteiro::buscarVisitanteData(){
    string buscarData;
    bool encontrou = false;

    system("clear || cls");
    cout << "Digite a data da visita: ";
    cin.ignore();
    getline(cin, buscarData);

    if(Visitantes.size() == 0){
        cout << "---Não há visitantes cadastrados!---\n" << endl;
    } else{
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
    }

    if(!encontrou){
        system("clear || cls");
        cout << "---Não há visitantes cadastrados nessa data!---\n" << endl;
    }
}

void Porteiro::listarEncomendas(){
    system("clear || cls");
    if(encomendas.size() == 0){
        cout << "---Não há encomendas cadastradas!" << endl;
    } else{
        cout << "       -----Lista de encomendas-----" << endl;
        for(int i = 0; i < encomendas.size(); i++){
            cout << "Nome do remetente: " << encomendas[i].getNomeRemetente() << endl;
            cout << "Nome do destinatário: " << encomendas[i].getNomeDestinatario() << endl;
            cout << "CPF do destinatário: " << encomendas[i].getCpfDestinatario() << endl;
            cout << "Número do apartamento: " << encomendas[i].getNumeroApartamento() << endl;
            cout << "Data de recebimento: " << encomendas[i].getDataRecebimento() << endl;
            cout << "---------------------------------\n" << endl;
        }
    }
}