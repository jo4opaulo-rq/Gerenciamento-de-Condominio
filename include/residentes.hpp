#ifndef RESIDENTES_HPP
#define RESIDENTES_HPP
#include <iostream>
#include "pessoa.hpp"

class Residentes : public Pessoa{
    private: 
    int predio;
    int apartamento;
    int andar;
    int vagaGaragem;
    std::string dataEntrada;
    std::string dataSaida;
    std::string telefone;
    std::string email;

    public: 
    Residentes();
    Residentes(std::string nome, std::string cpf, std::string dataNascimento, int predio, int apartamento, int andar, int vagaGaragem, std::string dataEntrada, std::string dataSaida, std::string telefone, std::string email);
    int getPredio();
    int getApartamento();
    int getAndar();
    int getVagaGaragem();
    std::string getDataEntrada();
    std::string getDataSaida();
    std::string getTelefone();
    std::string getEmail();
    void setPredio(int predio);
    void setApartamento(int apartamento);
    void setAndar(int andar);
    void setVagaGaragem(int vagaGaragem);
    void setDataEntrada(std::string dataEntrada);
    void setDataSaida(std::string dataSaida);
    void setTelefone(std::string telefone);
    void setEmail(std::string email);


};





#endif