#ifndef PORTERIO_HPP
#define PORTERIO_HPP
#include <iostream>
<<<<<<< Updated upstream
#include "funcionarios.hpp"
=======
#include "encomenda.hpp"
#include "visitante.hpp"
>>>>>>> Stashed changes
#include "residentes.hpp"
#include <vector>
#include <fstream>

<<<<<<< Updated upstream
class Porteiro : public Funcionarios, public Residentes{
    private:
        std::string turno;
        std::string portaria;
        std::string senha;
        std::vector<Residentes> residentes;
    public: 
        Porteiro();
        Porteiro(std::string nome, std::string cpf, std::string dataNascimento, std::string matricula, std::string funcao, std::string setor, float cargaHoraria, float salario, std::string turno, std::string portaria, std::string senha);
        std::string getTurno();
        std::string getPortaria();
        std::string getSenha();

        void setTurno(std::string turno);
        void setPortaria(std::string portaria);
        void setSenha(std::string senha);
        void lerArquivo(std::string nomeArquivo);
        void buscarResidente(std::string cpf);
        
        
=======
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
>>>>>>> Stashed changes
    };




#endif