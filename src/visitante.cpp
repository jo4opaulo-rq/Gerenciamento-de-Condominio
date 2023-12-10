#include <iostream>

#include "visitante.hpp"

using namespace std;

Visitante::Visitante(){
    nomeVisitado  = "";
    nomeVisitante = "";
    apartamento   = 0;
    andar         = 0;
    dataVisita    = "S/D";
}

Visitante::Visitante(string nomeVisitante, string nomeVisitado, int apartamento, int andar, string dataVisita){
    this->nomeVisitado  = nomeVisitado;
    this->nomeVisitante = nomeVisitante;
    this->apartamento   = apartamento;
    this->andar         = andar;
    this->dataVisita    = dataVisita;
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

string Visitante::getDataVisita(){
    return dataVisita;
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

void Visitante::setDataVisita(string dataVisita){
    this->dataVisita = dataVisita;
}