#ifndef LOGIN_HPP
#define LOGIN_HPP

#include <iostream>

class Login{
    private:
        std::string loginPorteiro = "porteiro";
        std::string senhaPorteiro = "porteiro";
        std::string loginAdministrador = "admin";
        std::string senhaAdministrador = "admin";
    public:
        bool fazerLogin(std::string funcao);
};

#endif