#ifndef PORTERIO_HPP
#define PORTERIO_HPP
#include <iostream>
#include "encomenda.hpp"
#include "visitante.hpp"
#include <vector>
#include <fstream>

class Porteiro : public Visitante, public Encomenda{
    private:
        std::vector<Visitante> residentes;
        std::vector<Encomenda> encomendas;
    public:
        void menuPorteiro();
        void lerArquivo(std::string nomeArquivo);
        void buscarEncomenda();
    };

#endif