#ifndef PORTERIO_HPP
#define PORTERIO_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include "funcionarios.hpp"
#include "encomenda.hpp"
#include "visitante.hpp"
#include "residentes.hpp"

  /**
 * @brief Classe que representa um Porteiro.
 * 
 * Esta classe herda características de Funcionarios, Encomenda, Visitante e Residentes.
 */
class Porteiro : public Visitante, public Encomenda, public Residentes {
private: 
    std::vector<Visitante>  Visitantes;  ///< Lista de visitantes cadastrados.
    std::vector<Encomenda>  encomendas;  ///< Lista de encomendas registradas.
    std::vector<Residentes> residente;   ///< Lista de residentes registrados.

public: 
      /**
     * @brief Exibe o menu do Porteiro.
     */
    void menuPorteiro();

      /**
     * @brief Lê informações de um arquivo e carrega os dados nas listas.
     * @param nomeArquivo Nome do arquivo a ser lido.
     */
    void lerArquivo(std::string nomeArquivo);

    /**
     * @brief Atualiza as informações do arquivo com base nas listas atuais.
     */
    void atualizarArquivo();

    /**
     * @brief Cadastra uma nova encomenda.
     */
    void cadastrarEncomenda();

    /**
     * @brief Cadastra um novo visitante.
     */
    void cadastrarVisitante();

    /**
     * @brief Lista todos os visitantes cadastrados.
     */
    void listarVisitantes();

    /**
     * @brief Busca uma encomenda pelo CPF.
     */
    void buscarEncomenda();

    /**
     * @brief Busca visitantes com base em uma data específica.
     */
    void buscarVisitanteData();
};

#endif
