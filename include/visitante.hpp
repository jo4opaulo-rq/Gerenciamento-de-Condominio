#ifndef VISITANTE_HPP
#define VISITANTE_HPP

#include <iostream>

class Visitante{
    private:
        std::string nomeVisitante;
        std::string nomeVisitado;
        std::string dataVisita;
        int apartamento;
        int andar;
    public:
        Visitante();
        Visitante(std::string nomeVisitante, std::string nomeVisitado, int apartamento, int andar, std::string dataVisita);
        std::string getNomeVisitante();
        std::string getNomeVisitado();
        int getApartamento();
        int getAndar();
        std::string getDataVisita();
        void setNomeVisitante(std::string nomeVisitante);
        void setNomeVisitado(std::string nomeVisitado);
        void setApartamento(int apartamento);
        void setAndar(int andar);
        void setDataVisita(std::string dataVisita);
};

#endif
