#include <iostream>

#include "seguranca.hpp"

using namespace std;

Seguranca::Seguranca(){
    this->salario = 0.0;
    this->turno = "";
    this->flagLeitura = false;
}

Seguranca::Seguranca(string nome, string cpf, string dataNascimento, string matricula, string funcao, string setor, float cargaHoraria, float salario, string turno, bool flagLeitura) : Funcionarios(matricula, funcao, setor, cargaHoraria, salario), Pessoa(nome, cpf, dataNascimento){
    if(flagLeitura){
        this->salario = salario;
    } else{
        if(turno == "noturno"){
            this->salario = salario + (salario * adicionalPericulosidade) + (salario * adicionalNoturno);
        } else{
            this->salario = salario + (salario * adicionalPericulosidade);
        }
    }
    this->turno = turno;
    this->flagLeitura = flagLeitura;
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
    if(flagLeitura){
        this->salario = salario;
    } else{
        if(turno == "noturno"){
            this->salario = salario + (salario * adicionalPericulosidade) + (salario * adicionalNoturno);
        } else{
            this->salario = salario + (salario * adicionalPericulosidade);
        }
    }
}

void Seguranca::setFlagLeitura(bool flagLeitura){
    this->flagLeitura = flagLeitura;
}
