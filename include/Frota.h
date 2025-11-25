#ifndef FROTA_H
#define FROTA_H

#include "Arvore.h"
#include "Veiculo.h"
#include "Carro.h"
#include "Caminhao.h"
#include "Moto.h"
#include <string>

/**
 * 
 *  @brief Classe responsável por armazenar uma arvore de veículos e realizar operações sobre ela, interagindo com o usuário
 * 
 */
class Frota{
    public:
        void inserirVeiculo();
        void buscarVeiculo();
        void imprimirVeiculos();
        void atualizarQuilometragem();
        void calculaCustoManutencao();
        void ativarDebug();

    private:
        Arvore<Veiculo> arvore;
        double custoMedioCarro = 0;
        double custoMedioMoto = 0;
        double custoMedioCaminhao = 0;

        // Usados para calculo do custo medio
        double quantidadeCarro = 0;
        double quantidadeMoto = 0;
        double quantidadeCaminhao = 0;

        // Auxiliar
        void percussoPrefixoCustoManutencao(No<Veiculo>& noAtual);
};

#endif