#ifndef ENCOMENDA_HPP
#define ENCOMENDA_HPP

#include <iostream>

class Encomenda{
    private:
        std::string nomeRemetente;
        std::string nomeDestinatario;
        std::string numeroApartamento;
        std::string dataRecebimento;
    public:
        Encomenda();
        Encomenda(std::string nomeRemetente, std::string nomeDestinatario, std::string numeroApartamento, std::string dataRecebimento);
        std::string getNomeRemetente();
        std::string getNomeDestinatario();
        std::string getNumeroApartamento();
        std::string getDataRecebimento();
        void setNomeRemetente(std::string nomeRemetente);
        void setNomeDestinatario(std::string nomeDestinatario);
        void setNumeroApartamento(std::string numeroApartamento);
        void setDataRecebimento(std::string dataRecebimento);
};

#endif