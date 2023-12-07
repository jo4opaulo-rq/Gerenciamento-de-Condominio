#include <iostream>

#include "zelador.hpp"

using namespace std;

Zelador::Zelador(){
    this->salario = 0.0;
    this->turno = "";
}

Zelador::Zelador(string nome, string cpf, string dataNascimento, string matricula, string funcao, string setor, float cargaHoraria, float salario, string turno) : Funcionarios(matricula, funcao, setor, cargaHoraria, salario), Pessoa(nome, cpf, dataNascimento){
    this->salario = salario + (salario * adicionalInsalubridade);
    this->turno = turno;
}

string Zelador::getTurno(){
    return turno;
}

float Zelador::getSalario(){
    return salario;
}

void Zelador::setTurno(string turno){
    this->turno = turno;
}

void Zelador::setSalario(float salario){
    this->salario = salario;
}
