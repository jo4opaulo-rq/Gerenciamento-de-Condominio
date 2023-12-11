#ifndef ADMINISTRADOR_HPP
#define ADMINISTRADOR_HPP

#include <iostream>
#include <vector>
#include <fstream>

#include "residentes.hpp"
#include "seguranca.hpp"
#include "zelador.hpp"

  /**
 * @brief Classe que representa um Administrador do sistema.
 *
 * Esta classe herda as funcionalidades de Residentes, Seguranca e Zelador.
 *@author Leandro Felix
 */
class Administrador : public Residentes, public Seguranca, public Zelador {
private: 
    std::vector<Residentes> residentes;  ///< Vetor que armazena os residentes cadastrados.
    std::vector<Seguranca>  segurancas;  ///< Vetor que armazena os seguranças cadastrados.
    std::vector<Zelador>    zeladores;   ///< Vetor que armazena os zeladores cadastrados.

public: 
      /**
     * @brief Exibe o menu de opções para o administrador.
     */
    void menuAdministrador();

      /**
     * @brief Lê os dados de um arquivo e os armazena em objetos de Residente, Zelador ou Segurança.
     * @param nomeArquivo Nome do arquivo a ser lido.
     */
    void lerArquivo(std::string nomeArquivo);

    /**
     * @brief Atualiza um arquivo com os dados armazenados nos objetos de Residente, Zelador ou Segurança.
     * @param nomeArquivo Nome do arquivo a ser atualizado.
     */
    void atualizarArquivo(std::string nomeArquivo);

    /**
     * @brief Lê um número inteiro da entrada padrão com validação.
     * @param numero Variável para armazenar o número lido.
     * @param msg Mensagem a ser exibida antes da leitura.
     * @return Número inteiro lido.
     */
    int lerInt(int numero, std::string msg);

    /**
     * @brief Lê um número de ponto flutuante da entrada padrão com validação.
     * @param numero Variável para armazenar o número lido.
     * @param msg Mensagem a ser exibida antes da leitura.
     * @return Número de ponto flutuante lido.
     */
    float lerFloat(float numero, std::string msg);

    /**
     * @brief Cadastra um novo residente com base nas informações fornecidas pelo administrador.
     */
    void cadastrarResidente();

    /**
     * @brief Cadastra um novo funcionário (Zelador ou Segurança) com base nas informações fornecidas pelo administrador.
     */
    void cadastrarFuncionario();

    /**
     * @brief Lista os residentes cadastrados.
     */
    void listarResidentes();

    /**
     * @brief Lista os funcionários (Zeladores e Seguranças) cadastrados.
     */
    void listarFuncionarios();

    /**
     * @brief Remove um residente com base no CPF fornecido.
     */
    void removerResidente();

    /**
     * @brief Remove um funcionário (Zelador ou Segurança) com base na matrícula e função fornecidas.
     */
    void removerFuncionario();

    /**
     * @brief Busca um residente com base no CPF fornecido.
     */
    void buscarResidente();

    /**
     * @brief Busca um funcionário (Zelador ou Segurança) com base na matrícula fornecida.
     */
    void buscarFuncionario();
};

#endif
