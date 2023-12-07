#include <iostream>

#include "seguranca.hpp"

using namespace std;

Seguranca::Seguranca(){
    this->salario = 0.0;
    this->turno = "";
}

Seguranca::Seguranca(string nome, string cpf, string dataNascimento, string matricula, string funcao, string setor, float cargaHoraria, float salario, string turno) : Funcionarios(matricula, funcao, setor, cargaHoraria, salario), Pessoa(nome, cpf, dataNascimento){
    if(turno == "Noturno"){
        this->salario = salario + (salario * adicionalNoturno) + (salario * adicionalPericulosidade);
    } else{
        this->salario = salario + (salario * adicionalPericulosidade);
    }

    this->turno = turno;
}

string Seguranca::getTurno(){
    return turno;
}

float Seguranca::getSalario(){
    return salario;
}

void Seguranca::setTurno(string turno){
    this->turno = turno;
}

void Seguranca::setSalario(float salario){
    if(turno == "noturno"){
        this->salario = salario + (salario * adicionalNoturno) + (salario * adicionalPericulosidade);
    } else{
        this->salario = salario + (salario * adicionalPericulosidade);
    }
}