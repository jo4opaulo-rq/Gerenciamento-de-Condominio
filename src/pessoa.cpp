#include <iostream>

#include "include/pessoa.hpp"

Pessoa::Pessoa(){}

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
