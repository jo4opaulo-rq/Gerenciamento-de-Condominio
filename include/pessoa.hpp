#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <iostream>

class Pessoa{
    /*
    @see Pessoa
    @brief Classe criada para servir de base para funcionários e residentes
    */
    private:
        std::string nome;
        std::string cpf;
        std::string dataNascimento;
      /*
          @details A classe Pessoa tem como atributos o nome, cpf e data de nascimento
    */
    public:
        Pessoa();
    /*
            @details Construtor padrão da classe Pessoa, construtor vazio
    */
        Pessoa(std::string nome, std::string cpf, std::string dataNascimento);
    /*
            @details Construtor parametrizado da classe Pessoa, construtor com parâmetros
    */
        std::string getNome();
      /*
@details Método utilizado para obter e retornar o valor no atributo nome
    */
        std::string getCpf();
        /*
@details Método utilizado para obter e retornar o valor no atributo cpf
    */
        std::string getDataNascimento();
    /*
@details Método utilizado para obter e retornar o valor no atributo data de nascimento

*/
        void setNome(std::string nome);
    /*
@details Método utilizado para atribuir um valor ao atributo nome
*/
        void setCpf(std::string cpf);
    /*
@details Método utilizado para atribuir um valor ao atributo cpf
*/
        void setDataNascimento(std::string dataNascimento);
    /*
@details Método utilizado para atribuir um valor ao atributo data de nascimento
*/
};

#endif