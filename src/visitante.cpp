#include <iostream>

#include "visitante.hpp"

using namespace std;

Visitante::Visitante(){
    nomeVisitado = "";
    nomeVisitante = "";
    apartamento = 0;
    andar = 0;
}

Visitante::Visitante(string nomeVisitante, string nomeVisitado, int apartamento, int andar){
    this->nomeVisitado = nomeVisitado;
    this->nomeVisitante = nomeVisitante;
    this->apartamento = apartamento;
    this->andar = andar;
}

string Visitante::getNomeVisitante(){
    return nomeVisitante;
}

string Visitante::getNomeVisitado(){
    return nomeVisitado;
}

int Visitante::getApartamento(){
    return apartamento;
}

int Visitante::getAndar(){
    return andar;
}

void Visitante::setNomeVisitante(string nomeVisitante){
    this->nomeVisitante = nomeVisitante;
}

void Visitante::setNomeVisitado(string nomeVisitado){
    this->nomeVisitado = nomeVisitado;
}

void Visitante::setApartamento(int apartamento){
    this->apartamento = apartamento;
}

void Visitante::setAndar(int andar){
    this->andar = andar;
}
