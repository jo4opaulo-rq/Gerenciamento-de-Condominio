#ifndef PORTERIO_HPP
#define PORTERIO_HPP
#include <iostream>
#include "funcionarios.hpp"
#include "encomenda.hpp"
#include "visitante.hpp"

#include "residentes.hpp"
#include <vector>
#include <fstream>

class Porteiro : public Visitante, public Encomenda, public Residentes{
    private:
        std::vector<Visitante> Visitantes;
        std::vector<Encomenda> encomendas;
        std::vector<Residentes> residente;
    public:
        void menuPorteiro();
        void lerArquivo(std::string nomeArquivo);
        void atualizarArquivo();
        void cadastrarEncomenda();
        void cadastrarVisitante();
        void listarVisitantes();
        void buscarEncomenda();
        void buscarVisitanteData();

    };

#endif