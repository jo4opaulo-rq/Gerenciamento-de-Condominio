#ifndef PORTERIO_HPP
#define PORTERIO_HPP
#include <iostream>
#include "funcionarios.hpp"
#include "encomenda.hpp"
#include "visitante.hpp"

#include "residentes.hpp"
#include <vector>
#include <fstream>


class Porteiro : public Funcionarios, public Residentes{

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
        void buscarResidente(std::string cpf);
        
     
class Porteiro : public Visitante, public Encomenda, public Residentes{
    private:
        std::vector<Visitante> Visitantes;
        std::vector<Encomenda> encomendas;
        std::vector<Residentes> residente;
    public:
        void menuPorteiro();
        void lerArquivo(std::string nomeArquivo);
        void buscarEncomenda();
        void cadastrarEncomenda();
        void cadastrarVisitante();
        void listarVisitantes();
        void buscarEncomenda();

    };

#endif