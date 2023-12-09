#ifndef SEGURANCA_HPP
#define SEGURANCA_HPP

#include <iostream>

#include "funcionarios.hpp"
#include "pessoa.hpp"

class Seguranca : public Funcionarios, public Pessoa{
    private:
        float adicionalPericulosidade = 0.3;
        float adicionalNoturno = 0.2;
        std::string turno;
        int flagLeitura;
    public:
        Seguranca();
        Seguranca(std::string nome, std::string cpf, std::string dataNascimento, std::string matricula, std::string funcao, std::string setor, float cargaHoraria, float salario, std::string turno, bool flagLeitura);
        std::string getTurno();
        float getSalario();
        void setTurno(std::string turno);
        void setSalario(float salario);
        void setFlagLeitura(bool flagLeitura);
};

#endif