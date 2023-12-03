#include <iostream>
#include "pessoa.hpp"

using namespace std;

int main(){
    Pessoa *Tobias = new Pessoa();
    cout << Tobias->getCpf();
}