#ifndef PORTEIROS_HPP
#define PORTEIROS_HPP

#include <iostream>
#include "funcionarios.hpp"

class Porteiros : public Funcionarios{
    private:
        std::string portaria;
        std::string turno;
    public:
        Porteiros();
        Porteiros(std::string nome, std::string cpf, std::string dataNascimento, std::string matricula, std::string funcao, float cargaHoraria, std::string portaria, std::string turno);
        std::string getPortaria();
        std::string getTurno();
        void setPortaria(std::string portaria);
        void setTurno(std::string turno);
};

#endif