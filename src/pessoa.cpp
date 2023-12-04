#include <iostream>

#include "pessoa.hpp"

Pessoa::Pessoa(){
    nome           = "-";
    cpf            = "000.000.000-00";
    dataNascimento = "00/00/0000";
}

Pessoa::Pessoa(std::string nome, std::string cpf, std::string dataNascimento){
    this->nome = nome;
    this->cpf = cpf;
    this->dataNascimento = dataNascimento;
}

std::string Pessoa::getNome(){
    return nome;
}

std::string Pessoa::getCpf(){
    return cpf;
}

std::string Pessoa::getDataNascimento(){
    return dataNascimento;
}

void Pessoa::setNome(std::string nome){
    this->nome = nome;
}

void Pessoa::setCpf(std::string cpf){
    this->cpf = cpf;
}

void Pessoa::setDataNascimento(std::string dataNascimento){
    this->dataNascimento = dataNascimento;
}
