#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <iostream>

class Pessoa{
    private:
        std::string nome;
        std::string cpf;
        std::string dataNascimento;
    public:
        Pessoa();
        Pessoa(std::string nome, std::string cpf, std::string dataNascimento);
        std::string getNome();
        std::string getCpf();
        std::string getDataNascimento();
        void setNome(std::string nome);
        void setCpf(std::string cpf);
        void setDataNascimento(std::string dataNascimento);
};

#endif