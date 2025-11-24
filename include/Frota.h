#ifndef FROTA_H
#define FROTA_H

#include "Arvore.h"
#include "Veiculo.h"
#include "Carro.h"
#include "Caminhao.h"
#include "Moto.h"
#include <string>

class Frota{
    public:
        void inserirVeiculo();
        void imprimirVeiculos();
    private:
        Arvore<Veiculo> arvore;
};

#endif