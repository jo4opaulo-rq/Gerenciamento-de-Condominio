#ifndef SEGURANCA_HPP
#define SEGURANCA_HPP

#include <iostream>

#include "funcionarios.hpp"
#include "pessoa.hpp"

/**
 * @brief Classe que representa um Segurança.
 *
 * Esta classe herda características de Funcionarios e Pessoa.
 * @author Leandro Felix
 */
class Seguranca : public Funcionarios, public Pessoa {
private:
    float adicionalPericulosidade = 0.3; ///< Valor do adicional de periculosidade para segurança.
    float adicionalNoturno = 0.2;        ///< Valor do adicional noturno para segurança.
    std::string turno;                   ///< Turno de trabalho do segurança.
    int flagLeitura;                     ///< Flag para identificar se os dados estão vindo da leitura de um arquivo ou não.

public:
    /**
     * @brief Construtor padrão da classe Seguranca.
     */
    Seguranca();

    /**
     * @brief Construtor da classe Seguranca.
     * @param nome Nome do segurança.
     * @param cpf CPF do segurança.
     * @param dataNascimento Data de nascimento do segurança.
     * @param matricula Matrícula do segurança.
     * @param funcao Função do segurança.
     * @param setor Setor do segurança.
     * @param cargaHoraria Carga horária do segurança.
     * @param salario Salário do segurança.
     * @param turno Turno de trabalho do segurança.
     * @param flagLeitura Indica se os dados recebidos pelo constructor são de um arquivo ou não.
     */
    Seguranca(std::string nome, std::string cpf, std::string dataNascimento, std::string matricula, std::string funcao, std::string setor, float cargaHoraria, float salario, std::string turno, bool flagLeitura);

    /**
     * @brief Obtém o turno de trabalho do segurança.
     * @return Turno de trabalho do segurança.
     */
    std::string getTurno();

    /**
     * @brief Obtém o salário do segurança.
     * @return Salário do segurança.
     */
    float getSalario();

    /**
     * @brief Define o turno de trabalho do segurança.
     * @param turno Turno de trabalho do segurança.
     * @details O salario é baseado na carga horária, no adicional de periculosidade e no adicional noturno.
     */
    void setTurno(std::string turno);

    /**
     * @brief Define o salário do segurança.
     * @param salario Salário do segurança.
     */
    void setSalario(float salario);

    /**
     * @brief Define a flag de leitura, indicando se os dados são provenientes de um arquivo.
     * @param flagLeitura Flag de leitura.
     * @details Se flagLeitura for true, o salário não será calculado.
     */
    void setFlagLeitura(bool flagLeitura);
};

#endif
