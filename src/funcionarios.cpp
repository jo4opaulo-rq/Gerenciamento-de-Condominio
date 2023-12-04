#include <iostream>
#include "funcionarios.hpp"
#include "pessoa.hpp"

using namespace std;

Funcionarios::Funcionarios(){
    matricula = "#00000";
    funcao    = "#";
    setor     = "--";
    cargaHoraria = 00.0;

}
Funcionarios::Funcionarios(string nome, string cpf, string dataNascimento, string matricula, string funcao, float cargaHoraria): Pessoa(nome, cpf, dataNascimento){
    this->matricula = matricula;
    this->funcao       = funcao;
    this->setor        = setor;
    this->cargaHoraria = cargaHoraria;
    
}

string Funcionarios::getMatricula(){
    return this->matricula;
}
string Funcionarios::getFuncao(){
    return this->funcao;
}
string Funcionarios::getSetor(){
    return this->setor;
}
float Funcionarios::getCargaHoraria(){
    return this->cargaHoraria;
}

 void Funcionarios::setMatricula(std::string matricula){
    this->matricula = matricula;
 }
void Funcionarios::setFuncao(std::string funcao){
    this->funcao       = funcao;
}
void Funcionarios::setSetor(std::string setor){
    this->setor        = setor;
}
void Funcionarios::setCargaHoraria(float cargaHoraria){
    this->cargaHoraria = cargaHoraria;
}