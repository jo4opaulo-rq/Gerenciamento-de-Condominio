#ifndef ZELADOR_HPP
#define ZELADOR_HPP

#include <iostream>

#include "funcionarios.hpp"
#include "pessoa.hpp"

class Zelador : public Funcionarios, public Pessoa{
    private:
        float adicionalInsalubridade = 0.1;
        std::string turno;
    public:
        Zelador();
        Zelador(std::string nome, std::string cpf, std::string dataNascimento, std::string matricula, std::string funcao, std::string setor, float cargaHoraria, float salario, std::string turno);
        std::string getTurno();
        void setTurno(std::string turno);
        float getSalario();
        void setSalario(float salario);
};

#endif
