#include <iostream>

#include "encomenda.hpp"

using namespace std;

Encomenda::Encomenda(){
    this->nomeRemetente = "";
    this->nomeDestinatario = "";
    this->numeroApartamento = "";
    this->dataRecebimento = "";
}

Encomenda::Encomenda(string nomeRemetente, string nomeDestinatario, string numeroApartamento, string dataRecebimento){
    this->nomeRemetente = nomeRemetente;
    this->nomeDestinatario = nomeDestinatario;
    this->numeroApartamento = numeroApartamento;
    this->dataRecebimento = dataRecebimento;
}

string Encomenda::getNomeRemetente(){
    return nomeRemetente;
}

string Encomenda::getNomeDestinatario(){
    return nomeDestinatario;
}

string Encomenda::getNumeroApartamento(){
    return numeroApartamento;
}

string Encomenda::getDataRecebimento(){
    return dataRecebimento;
}

void Encomenda::setNomeRemetente(string nomeRemetente){
    this->nomeRemetente = nomeRemetente;
}

void Encomenda::setNomeDestinatario(string nomeDestinatario){
    this->nomeDestinatario = nomeDestinatario;
}

void Encomenda::setNumeroApartamento(string numeroApartamento){
    this->numeroApartamento = numeroApartamento;
}

void Encomenda::setDataRecebimento(string dataRecebimento){
    this->dataRecebimento = dataRecebimento;
}
