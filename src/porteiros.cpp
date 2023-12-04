#include <iostream>

#include "porteiros.hpp"

Porteiros::Porteiros() : Funcionarios(){
    this->portaria = "";
    this->turno = "";
}

Porteiros::Porteiros(std::string nome, std::string cpf, std::string dataNascimento, std::string matricula, std::string funcao, float cargaHoraria, std::string portaria, std::string turno) : Funcionarios(nome, cpf, dataNascimento, matricula, funcao, cargaHoraria){
    this->portaria = portaria;
    this->turno = turno;
}

std::string Porteiros::getPortaria(){
    return this->portaria;
}

std::string Porteiros::getTurno(){
    return this->turno;
}

void Porteiros::setPortaria(std::string portaria){
    this->portaria = portaria;
}

void Porteiros::setTurno(std::string turno){
    this->turno = turno;
}

