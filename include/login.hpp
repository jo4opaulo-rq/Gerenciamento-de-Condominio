#ifndef LOGIN_HPP
#define LOGIN_HPP

#include <iostream>
#include "administrador.hpp"
#include "porteiro.hpp"

  /**
 * @brief Classe que representa o sistema de login.
 *
 * Esta classe é responsável por autenticar usuários como Administrador ou Porteiro.
 */
class Login {
private:
    std::string loginPorteiro      = "porteiro";  ///< Login padrão para o porteiro.
    std::string senhaPorteiro      = "porteiro";  ///< Senha padrão para o porteiro.
    std::string loginAdministrador = "admin";     ///< Login padrão para o administrador.
    std::string senhaAdministrador = "admin";     ///< Senha padrão para o administrador.

public:
    /**
     * @brief Realiza o processo de login.
     *
     * @param funcao Função a ser autenticada (Administrador ou Porteiro).
     * @return true se o login for bem-sucedido, false caso contrário.
     */
    bool fazerLogin(std::string funcao);


    /**
     * @brief Lê um número inteiro da entrada padrão com validação.
     * @param numero Variável para armazenar o número lido.
     * @param msg Mensagem a ser exibida antes da leitura.
     * @return Número inteiro lido.
    */
    int lerInt(int numero, std::string msg);

    /**
     * @brief Exibe a tela do administrador após o login bem-sucedido.
     */
    void telaAdministrador();

    /**
     * @brief Exibe a tela do porteiro após o login bem-sucedido.
     */
    void telaPorteiro();
};

#endif
