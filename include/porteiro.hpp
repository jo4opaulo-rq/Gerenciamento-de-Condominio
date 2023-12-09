#ifndef PORTERIO_HPP
#define PORTERIO_HPP
#include <iostream>
#include "funcionarios.hpp"
#include "residentes.hpp"
#include <vector>
#include <fstream>

class Porteiro : public Funcionarios, public Residentes{
    private:
        std::string turno;
        std::string portaria;
        std::string senha;
        std::vector<Residentes> residentes;
    public: 
        Porteiro();
        Porteiro(std::string nome, std::string cpf, std::string dataNascimento, std::string matricula, std::string funcao, std::string setor, float cargaHoraria, float salario, std::string turno, std::string portaria, std::string senha);
        std::string getTurno();
        std::string getPortaria();
        std::string getSenha();

        void setTurno(std::string turno);
        void setPortaria(std::string portaria);
        void setSenha(std::string senha);
        void buscarResidente(std::string cpf);
        
        
    };




#endif