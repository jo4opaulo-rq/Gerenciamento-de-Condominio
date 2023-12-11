#ifndef FUNCIONARIOS_HPP
#define FUNCIONARIOS_HPP

#include <iostream>

/**
 * @brief Classe que representa um funcionário.
 * @author Leandro Felix
 */
class Funcionarios {
protected:
    std::string matricula;      /**< Matrícula do funcionário */
    std::string funcao;         /**< Função que o funcionário exerce */
    std::string setor;          /**< Setor onde o funcionário trabalha */
    float cargaHoraria;         /**< Carga horária semanal do funcionário */
    float salario;              /**< Salário do funcionário */

public:
    /**
     * @brief Construtor padrão.
     */
    Funcionarios();

    /**
     * @brief Construtor com parâmetros para inicializar os atributos.
     * @param matricula Matrícula do funcionário.
     * @param funcao Função que o funcionário exerce.
     * @param setor Setor onde o funcionário trabalha.
     * @param cargaHoraria Carga horária semanal do funcionário.
     * @param salario Salário do funcionário.
     */
    Funcionarios(std::string matricula, std::string funcao, std::string setor, float cargaHoraria, float salario);

    /**
     * @brief Obtém a matrícula do funcionário.
     * @return Matrícula do funcionário.
     */
    std::string getMatricula();

    /**
     * @brief Obtém a função do funcionário.
     * @return Função do funcionário.
     */
    std::string getFuncao();

    /**
     * @brief Obtém o setor do funcionário.
     * @return Setor do funcionário.
     */
    std::string getSetor();

    /**
     * @brief Obtém a carga horária do funcionário.
     * @return Carga horária do funcionário.
     */
    float getCargaHoraria();

    /**
     * @brief Método virtual puro para obter o salário do funcionário.
     * @return Salário do funcionário.
     * @details Deve ser implementado nas classes derivadas.
     */
    virtual float getSalario() = 0;

    /**
     * @brief Define a matrícula do funcionário.
     * @param matricula Nova matrícula do funcionário.
     */
    void setMatricula(std::string matricula);

    /**
     * @brief Define a função do funcionário.
     * @param funcao Nova função do funcionário.
     */
    void setFuncao(std::string funcao);

    /**
     * @brief Define o setor do funcionário.
     * @param setor Novo setor do funcionário.
     */
    void setSetor(std::string setor);

    /**
     * @brief Define a carga horária do funcionário.
     * @param cargaHoraria Nova carga horária do funcionário.
     */
    void setCargaHoraria(float cargaHoraria);

    /**
     * @brief Método virtual puro para definir o salário do funcionário.
     * @param salario Novo salário do funcionário.
     * @details Deve ser implementado nas classes derivadas.
     */
    virtual void setSalario(float salario) = 0;
};

#endif
