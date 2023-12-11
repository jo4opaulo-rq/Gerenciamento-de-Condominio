#ifndef ENCOMENDA_HPP
#define ENCOMENDA_HPP

#include <iostream>

/**
 *@brief Classe que representa uma encomenda.
 *@author João Paulo
 */
class Encomenda {
private:
    std::string nomeRemetente;      ///< Nome do remetente da encomenda.
    std::string nomeDestinatario;   ///< Nome do destinatário da encomenda.
    std::string cpfDestinatario;    ///< CPF do destinatário da encomenda.
    std::string numeroApartamento;  ///< Número do apartamento da encomenda.
    std::string dataRecebimento;    ///< Data de recebimento da encomenda.

public:
      /**
     * @brief Construtor padrão da classe Encomenda.
     */
    Encomenda();

      /**
     * @brief Construtor que inicializa os membros da classe com valores específicos.
     * @param nomeRemetente Nome do remetente da encomenda.
     * @param nomeDestinatario Nome do destinatário da encomenda.
     * @param cpfDestinatario CPF do destinatário da encomenda.
     * @param numeroApartamento Número do apartamento da encomenda.
     * @param dataRecebimento Data de recebimento da encomenda.
     */
    Encomenda(std::string nomeRemetente, std::string nomeDestinatario, std::string cpfDestinatario, std::string numeroApartamento, std::string dataRecebimento);

    /**
     * @brief Obtém o nome do remetente da encomenda.
     * @return Nome do remetente.
     */
    std::string getNomeRemetente();

    /**
     * @brief Obtém o nome do destinatário da encomenda.
     * @return Nome do destinatário.
     */
    std::string getNomeDestinatario();

    /**
     * @brief Obtém o CPF do destinatário da encomenda.
     * @return CPF do destinatário.
     */
    std::string getCpfDestinatario();

    /**
     * @brief Obtém o número do apartamento da encomenda.
     * @return Número do apartamento.
     */
    std::string getNumeroApartamento();

    /**
     * @brief Obtém a data de recebimento da encomenda.
     * @return Data de recebimento.
     */
    std::string getDataRecebimento();

    /**
     * @brief Define o nome do remetente da encomenda.
     * @param nomeRemetente Nome do remetente.
     */
    void setNomeRemetente(std::string nomeRemetente);

    /**
     * @brief Define o nome do destinatário da encomenda.
     * @param nomeDestinatario Nome do destinatário.
     */
    void setNomeDestinatario(std::string nomeDestinatario);

    /**
     * @brief Define o CPF do destinatário da encomenda.
     * @param cpfDestinatario CPF do destinatário.
     */
    void setCpfDestinatario(std::string cpfDestinatario);

    /**
     * @brief Define o número do apartamento da encomenda.
     * @param numeroApartamento Número do apartamento.
     */
    void setNumeroApartamento(std::string numeroApartamento);

    /**
     * @brief Define a data de recebimento da encomenda.
     * @param dataRecebimento Data de recebimento.
     */
    void setDataRecebimento(std::string dataRecebimento);
};

#endif
