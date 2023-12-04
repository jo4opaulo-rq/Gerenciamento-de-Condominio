#ifndef FUNCIONARIOS_HPP
#define FUNCIONARIOS_HPP
#include <iostream>
#include "pessoa.hpp"

class Funcionarios: public Pessoa{
    private: 
    std::string matricula;
    std::string funcao;
    std::string setor;
    float cargaHoraria;


    public: 
    Funcionarios();
    Funcionarios(std::string nome, std::string cpf, std::string dataNascimento, std::string matricula, std::string funcao, float cargaHoraria);
    std::string getMatricula();
    std::string getFuncao();
    std::string getSetor();
    float getCargaHoraria();
    void setMatricula(std::string matricula);
    void setFuncao(std::string funcao);
    void setSetor(std::string setor);
    void setCargaHoraria(float cargaHoraria);

};



#endif