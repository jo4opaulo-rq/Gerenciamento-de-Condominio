#ifndef FUNCIONARIOS_HPP
#define FUNCIONARIOS_HPP
#include <iostream>
#include "pessoa.hpp"

class Funcionarios : public Pessoa{
    protected:
        std::string matricula;
        std::string funcao;
        std::string setor;
        float cargaHoraria;
        float salario;
    public:
        Funcionarios();
        Funcionarios(std::string matricula, std::string funcao, std::string setor, float cargaHoraria, float salario);
        std::string getMatricula();
        std::string getFuncao();
        std::string getSetor();
        float getCargaHoraria();
        virtual float getSalario() = 0;
        void setMatricula(std::string matricula);
        void setFuncao(std::string funcao);
        void setSetor(std::string setor);
        void setCargaHoraria(float cargaHoraria);
        virtual void setSalario(float salario) = 0;
};



#endif