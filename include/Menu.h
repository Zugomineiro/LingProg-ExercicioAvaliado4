#ifndef MENU_H
#define MENU_H

#include <iomanip>
#include <iostream>
#include <exception>
#include "Veiculo.h"
#include "Frota.h"

/**
 * 
 * @brief Classe responsavel por interagir com o usuario e controlar o fluxo do programa
 * 
 */
class Menu{
    public:
        void imprimirMenu(); // Imprime o menu
        void executaOpcao(); // Responsavel por executar acao escolhida pelo usuario
        bool usuarioQuerSair(); // Método get para saber se o usuario quer terminar o programa
    
    private:
        static const int larguraMenu = 51; // Largura do menu em caracteres
        bool usuarioSaiu = false; // Booleano que diz se o usuario quer sair


        // Funcoes auxiliares
        

        // Atributos de dados principais do programa
        Frota frota;
        
};

#endif