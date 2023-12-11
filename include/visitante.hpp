#ifndef VISITANTE_HPP
#define VISITANTE_HPP

#include <iostream>

  /**
 * @brief Classe que representa um Visitante.
 * @author João Paulo
 */
class Visitante {
private:
    std::string nomeVisitante;  ///< Nome do visitante.
    std::string nomeVisitado;   ///< Nome da pessoa visitada.
    std::string dataVisita;     ///< Data da visita.
    int         apartamento;    ///< Número do apartamento visitado.
    int         andar;          ///< Número do andar visitado.

public:
      /**
     * @brief Construtor padrão da classe Visitante.
     */
    Visitante();

      /**
     * @brief Construtor da classe Visitante.
     * @param nomeVisitante Nome do visitante.
     * @param nomeVisitado Nome da pessoa visitada.
     * @param apartamento Número do apartamento visitado.
     * @param andar Número do andar visitado.
     * @param dataVisita Data da visita.
     */
    Visitante(std::string nomeVisitante, std::string nomeVisitado, int apartamento, int andar, std::string dataVisita);

    /**
     * @brief Obtém o nome do visitante.
     * @return Nome do visitante.
     */
    std::string getNomeVisitante();

    /**
     * @brief Obtém o nome da pessoa visitada.
     * @return Nome da pessoa visitada.
     */
    std::string getNomeVisitado();

    /**
     * @brief Obtém o número do apartamento visitado.
     * @return Número do apartamento visitado.
     */
    int getApartamento();

    /**
     * @brief Obtém o número do andar visitado.
     * @return Número do andar visitado.
     */
    int getAndar();

    /**
     * @brief Obtém a data da visita.
     * @return Data da visita.
     */
    std::string getDataVisita();

    /**
     * @brief Define o nome do visitante.
     * @param nomeVisitante Nome do visitante.
     */
    void setNomeVisitante(std::string nomeVisitante);

    /**
     * @brief Define o nome da pessoa visitada.
     * @param nomeVisitado Nome da pessoa visitada.
     */
    void setNomeVisitado(std::string nomeVisitado);

    /**
     * @brief Define o número do apartamento visitado.
     * @param apartamento Número do apartamento visitado.
     */
    void setApartamento(int apartamento);

    /**
     * @brief Define o número do andar visitado.
     * @param andar Número do andar visitado.
     */
    void setAndar(int andar);

    /**
     * @brief Define a data da visita.
     * @param dataVisita Data da visita.
     */
    void setDataVisita(std::string dataVisita);
};

#endif
