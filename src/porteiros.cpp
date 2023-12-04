#include <iostream>

#include "porteiros.hpp"

using namespace std;

Porteiros::Porteiros() : Funcionarios(){
    this->portaria = "";
    this->turno = "";
}

Porteiros::Porteiros(string nome, string cpf, string dataNascimento, string matricula, string funcao, float cargaHoraria, string portaria, string turno) : Funcionarios(nome, cpf, dataNascimento, matricula, funcao, cargaHoraria){
    this->portaria = portaria;
    this->turno = turno;
}

string Porteiros::getPortaria(){
    return this->portaria;
}

string Porteiros::getTurno(){
    return this->turno;
}

void Porteiros::setPortaria(string portaria){
    this->portaria = portaria;
}

void Porteiros::setTurno(string turno){
    this->turno = turno;
}

