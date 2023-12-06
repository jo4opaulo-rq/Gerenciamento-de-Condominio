#include <iostream>
#include "funcionarios.hpp"
#include "pessoa.hpp"

using namespace std;

Funcionarios::Funcionarios(){
    matricula = "#00000";
    funcao    = "#";
    setor     = "--";
    cargaHoraria = 00.0;
    salario = 00.0;
}
Funcionarios::Funcionarios(std::string matricula, std::string funcao, std::string setor, float cargaHoraria, float salario){
    this->matricula = matricula;
    this->funcao    = funcao;
    this->setor     = setor;
    this->cargaHoraria = cargaHoraria;
    this->salario = salario;
}

string Funcionarios::getMatricula(){
    return matricula;
}

string Funcionarios::getFuncao(){
    return funcao;
}

string Funcionarios::getSetor(){
    return setor;
}

float Funcionarios::getCargaHoraria(){
    return cargaHoraria;
}

void Funcionarios::setMatricula(string matricula){
    this->matricula = matricula;
}

void Funcionarios::setFuncao(string funcao){
    this->funcao = funcao;
}

void Funcionarios::setSetor(string setor){
    this->setor = setor;
}

void Funcionarios::setCargaHoraria(float cargaHoraria){
    this->cargaHoraria = cargaHoraria;
}
