#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <iostream>

  /**
 * @brief Classe que representa uma pessoa.
 * 
 * Esta classe contém informações básicas sobre uma pessoa, como nome, CPF e data de nascimento.
 */
class Pessoa {
private: 
    std::string nome;            ///< Nome da pessoa.
    std::string cpf;             ///< CPF da pessoa.
    std::string dataNascimento;  ///< Data de nascimento da pessoa.

public: 
      /**
     * @brief Construtor padrão da classe Pessoa.
     */
    Pessoa();

      /**
     * @brief Construtor que inicializa os membros da classe com valores específicos.
     * @param nome Nome da pessoa.
     * @param cpf CPF da pessoa.
     * @param dataNascimento Data de nascimento da pessoa.
     */
    Pessoa(std::string nome, std::string cpf, std::string dataNascimento);

    /**
     * @brief Obtém o nome da pessoa.
     * @return Nome da pessoa.
     */
    std::string getNome();

    /**
     * @brief Obtém o CPF da pessoa.
     * @return CPF da pessoa.
     */
    std::string getCpf();

    /**
     * @brief Obtém a data de nascimento da pessoa.
     * @return Data de nascimento da pessoa.
     */
    std::string getDataNascimento();

    /**
     * @brief Define o nome da pessoa.
     * @param nome Nome da pessoa.
     */
    void setNome(std::string nome);

    /**
     * @brief Define o CPF da pessoa.
     * @param cpf CPF da pessoa.
     */
    void setCpf(std::string cpf);

    /**
     * @brief Define a data de nascimento da pessoa.
     * @param dataNascimento Data de nascimento da pessoa.
     */
    void setDataNascimento(std::string dataNascimento);
};

#endif
