#include <iostream>
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
