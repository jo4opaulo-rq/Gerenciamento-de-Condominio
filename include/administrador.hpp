#ifndef ADMINISTRADOR_HPP
#define ADMINISTRADOR_HPP

#include <iostream>
#include <vector>
#include <fstream>

#include "residentes.hpp"
#include "seguranca.hpp"
#include "zelador.hpp"

class Administrador : public Residentes, public Seguranca, public Zelador{
    private:
        std::vector<Residentes> residentes;
        std::vector<Seguranca> segurancas;
        std::vector<Zelador> zeladores;
    public:
        void menuAdministrador();
        void lerArquivo(std::string nomeArquivo);
        void atualizarArquivo(std::string nomeArquivo);
        int lerInt(int numero, std::string msg);
        float lerFloat(float numero, std::string msg);
        void cadastrarResidente();
        void cadastrarFuncionario();
        void listarResidentes();
        void listarFuncionarios();
        void removerResidente();
        void removerFuncionario();
        void buscarResidente();
        void buscarFuncionario();
};

#endif