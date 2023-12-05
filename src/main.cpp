#include <iostream>
// #include "pessoa.hpp"
#include "porteiros.hpp"
#include "residentes.hpp"
#include "visitante.hpp"

using namespace std;

int main(){

    //Visitante(string nomeVisitante, string nomeVisitado, int apartamento, int andar);

    Visitante visitante1("João", "Maria", 1, 1);

    cout << "Nome do visitante: " << visitante1.getNomeVisitante() << endl;
    cout << "Nome do visitado: " << visitante1.getNomeVisitado() << endl;
    cout << "Apartamento: " << visitante1.getApartamento() << endl;
    cout << "Andar: " << visitante1.getAndar() << endl;

    return 0;
}