#ifndef VISITANTE_HPP
#define VISITANTE_HPP

#include <iostream>

class Visitante{
    private:
        std::string nomeVisitante;
        std::string nomeVisitado;
        int apartamento;
        int andar;
    public:
        Visitante();
        Visitante(std::string nomeVisitante, std::string nomeVisitado, int apartamento, int andar);
        std::string getNomeVisitante();
        std::string getNomeVisitado();
        int getApartamento();
        int getAndar();
        void setNomeVisitante(std::string nomeVisitante);
        void setNomeVisitado(std::string nomeVisitado);
        void setApartamento(int apartamento);
        void setAndar(int andar);
};

#endif
