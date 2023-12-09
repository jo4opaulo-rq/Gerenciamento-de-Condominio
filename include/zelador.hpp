#ifndef ZELADOR_HPP
#define ZELADOR_HPP

#include <iostream>

#include "funcionarios.hpp"
#include "pessoa.hpp"

class Zelador : public Funcionarios, public Pessoa{
    private:
        float adicionalInsalubridade = 0.1;
        std::string turno;
        bool flagLeitura;
    public:
        Zelador();
        Zelador(std::string nome, std::string cpf, std::string dataNascimento, std::string matricula, std::string funcao, std::string setor, float cargaHoraria, float salario, std::string turno, bool flagLeitura);
        std::string getTurno();
        float getSalario();
        void setTurno(std::string turno);
        void setSalario(float salario);
        void setFlagLeitura(bool flagLeitura);
};

#endif
