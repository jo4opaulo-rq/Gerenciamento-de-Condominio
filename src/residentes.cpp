#include <iostream>
#include "residentes.hpp"

using namespace std;

Residentes::Residentes(){
    this->predio = 0;
    this->apartamento = 0;
    this->andar = 0;
    this->vagaGaragem = 0;
    this->dataEntrada = "00/00/0000";
    this->dataSaida = "00/00/0000";
    this->telefone = "(00) 00000-0000";
    this->email = "residente@email.com";
}
Residentes::Residentes(string nome, string cpf, string dataNascimento, int predio, int apartamento, int andar, int vagaGaragem, string dataEntrada, string dataSaida, string telefone, string email):Pessoa(nome, cpf, dataNascimento){
    this->predio = predio;
    this->apartamento = apartamento;
    this->andar = andar;
    this->vagaGaragem = vagaGaragem;
    this->dataEntrada = dataEntrada;
    this->dataSaida = dataSaida;
    this->telefone = telefone;
    this->email = email;
}
int Residentes::getPredio(){
    return this->predio;
}
int Residentes::getApartamento(){
    return this->apartamento;
}
int Residentes::getAndar(){
    return this->andar;
}
int Residentes::getVagaGaragem(){
    return this->vagaGaragem;
}
string Residentes::getDataEntrada(){
    return this->dataEntrada;
}
string Residentes::getDataSaida(){
    return this->dataSaida;
}
string Residentes::getTelefone(){
    return this->telefone;
}
string Residentes::getEmail(){
    return this->email;
}
void Residentes::setPredio(int predio){
    this->predio = predio;
}
void Residentes::setApartamento(int apartamento){
    this->apartamento = apartamento;
}
void Residentes::setAndar(int andar){
    this->andar = andar;
}
void Residentes::setVagaGaragem(int vagaGaragem){
    this->vagaGaragem = vagaGaragem;
}
void Residentes::setDataEntrada(string dataEntrada){
    this->dataEntrada = dataEntrada;
}
void Residentes::setDataSaida(string dataSaida){
    this->dataSaida = dataSaida;
}
void Residentes::setTelefone(string telefone){
    this->telefone = telefone;
}
void Residentes::setEmail(string email){
    this->email = email;
}