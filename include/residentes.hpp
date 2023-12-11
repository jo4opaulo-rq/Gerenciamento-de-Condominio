#ifndef RESIDENTES_HPP
#define RESIDENTES_HPP

#include <iostream>
#include "pessoa.hpp"

/**
 * @brief Classe que representa um Residente.
 *
 * Esta classe herda características de Pessoa.
 * @author Leandro Felix
 */
class Residentes : public Pessoa {
private:
    int predio;            ///< Número do prédio onde o residente mora.
    int apartamento;       ///< Número do apartamento do residente.
    int andar;             ///< Número do andar onde o apartamento está localizado.
    int vagaGaragem;       ///< Número da vaga de garagem do residente.
    std::string dataEntrada; ///< Data de entrada do residente.
    std::string dataSaida;   ///< Data de saída do residente.
    std::string telefone;    ///< Número de telefone do residente.
    std::string email;       ///< Endereço de e-mail do residente.

public:
    /**
     * @brief Construtor padrão da classe Residentes.
     */
    Residentes();

    /**
     * @brief Construtor da classe Residentes.
     * @param nome Nome do residente.
     * @param cpf CPF do residente.
     * @param dataNascimento Data de nascimento do residente.
     * @param predio Número do prédio.
     * @param apartamento Número do apartamento.
     * @param andar Número do andar.
     * @param vagaGaragem Número da vaga de garagem.
     * @param dataEntrada Data de entrada.
     * @param dataSaida Data de saída.
     * @param telefone Número de telefone.
     * @param email Endereço de e-mail.
     */
    Residentes(std::string nome, std::string cpf, std::string dataNascimento, int predio, int apartamento, int andar, int vagaGaragem, std::string dataEntrada, std::string dataSaida, std::string telefone, std::string email);

    /**
     * @brief Obtém o número do prédio.
     * @return Número do prédio.
     */
    int getPredio();

    /**
     * @brief Obtém o número do apartamento.
     * @return Número do apartamento.
     */
    int getApartamento();

    /**
     * @brief Obtém o número do andar.
     * @return Número do andar.
     */
    int getAndar();

    /**
     * @brief Obtém o número da vaga de garagem.
     * @return Número da vaga de garagem.
     */
    int getVagaGaragem();

    /**
     * @brief Obtém a data de entrada.
     * @return Data de entrada.
     */
    std::string getDataEntrada();

    /**
     * @brief Obtém a data de saída.
     * @return Data de saída.
     */
    std::string getDataSaida();

    /**
     * @brief Obtém o número de telefone.
     * @return Número de telefone.
     */
    std::string getTelefone();

    /**
     * @brief Obtém o endereço de e-mail.
     * @return Endereço de e-mail.
     */
    std::string getEmail();

    // Métodos de modificação dos atributos
    /**
     * @brief Define o número do prédio.
     * @param predio Número do prédio.
     */
    void setPredio(int predio);

    /**
     * @brief Define o número do apartamento.
     * @param apartamento Número do apartamento.
     */
    void setApartamento(int apartamento);

    /**
     * @brief Define o número do andar.
     * @param andar Número do andar.
     */
    void setAndar(int andar);

    /**
     * @brief Define o número da vaga de garagem.
     * @param vagaGaragem Número da vaga de garagem.
     */
    void setVagaGaragem(int vagaGaragem);

    /**
     * @brief Define a data de entrada.
     * @param dataEntrada Data de entrada.
     */
    void setDataEntrada(std::string dataEntrada);

    /**
     * @brief Define a data de saída.
     * @param dataSaida Data de saída.
     */
    void setDataSaida(std::string dataSaida);

    /**
     * @brief Define o número de telefone.
     * @param telefone Número de telefone.
     */
    void setTelefone(std::string telefone);

    /**
     * @brief Define o endereço de e-mail.
     * @param email Endereço de e-mail.
     */
    void setEmail(std::string email);
};

#endif
