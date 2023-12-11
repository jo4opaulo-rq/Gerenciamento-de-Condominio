#ifndef ZELADOR_HPP
#define ZELADOR_HPP

#include <iostream>

#include "funcionarios.hpp"
#include "pessoa.hpp"

  /**
 * @brief Classe que representa um Zelador.
 *
 * Esta classe herda características de Funcionarios e Pessoa.
 * @author Leandro Felix
 */
class Zelador : public Funcionarios, public Pessoa {
private:
    float       adicionalInsalubridade = 0.1;  ///< Valor do adicional de insalubridade para o zelador.
    std::string turno;                         ///< Turno de trabalho do zelador.
    bool        flagLeitura;                   ///< Flag para identificar se os dados estão vindo da leitura de um arquivo ou não.

public:
      /**
     * @brief Construtor padrão da classe Zelador.
     */
    Zelador();

    /**
     * @brief Construtor da classe Zelador.
     * @param nome Nome do zelador.
     * @param cpf CPF do zelador.
     * @param dataNascimento Data de nascimento do zelador.
     * @param matricula Matrícula do zelador.
     * @param funcao Função do zelador.
     * @param setor Setor do zelador.
     * @param cargaHoraria Carga horária do zelador.
     * @param salario Salário do zelador.
     * @param turno Turno de trabalho do zelador.
     * @param flagLeitura Indica se os dados recebidos pelo constructor são de um arquivo ou não.
     */
    Zelador(std::string nome, std::string cpf, std::string dataNascimento, std::string matricula, std::string funcao, std::string setor, float cargaHoraria, float salario, std::string turno, bool flagLeitura);

    // Métodos de acesso aos atributos
    /**
     * @brief Obtém o turno de trabalho do zelador.
     * @return Turno de trabalho.
     */
    std::string getTurno();

    /**
     * @brief Obtém o salário do zelador.
     * @return Salário do zelador.
     * @details O salário é baseado na carga horária e no adicional de insalubridade.
     */
    float getSalario();

    // Métodos de modificação dos atributos
    /**
     * @brief Define o turno de trabalho do zelador.
     * @param turno Turno de trabalho.
     */
    void setTurno(std::string turno);

    /**
     * @brief Define o salário do zelador.
     * @param salario Salário do zelador.
     */
    void setSalario(float salario);

    /**
     * @brief Define a flag de leitura.
     * @param flagLeitura Indica se os dados estão vindo da leitura de um arquivo ou não.
     * @details  Se os dados vierem de um arquivo, o salário não será calculado.
     */
    void setFlagLeitura(bool flagLeitura);
};

#endif
