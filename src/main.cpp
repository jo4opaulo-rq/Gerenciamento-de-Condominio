#include <iostream>
// #include "pessoa.hpp"
#include "funcionarios.hpp"
#include "residentes.hpp"

using namespace std;

int main(){
    Residentes *residente = new Residentes("João", "000.000.000-00", "00/00/0000", 1, 1, 1, 1, "00/00/0000", "00/00/0000", "(00) 00000-0000, (87) 98998-0099", "joao@email.com");

    cout << residente->getNome() << endl;
    cout << residente->getTelefone() << endl;
}