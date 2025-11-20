#ifndef CAMINHAO_H
#define CAMINHAO_H

#include "Veiculo.h"

class Caminhao : public Veiculo{
    public:
        Caminhao(std::string placa,std::string marca,double capacidadeCarga);
        virtual void mostrarInformacoes(std::ostream& out = std::cout) const;
        virtual double calcularCustoManutencao() const;
    private:
        double capacidadeCarga; // Em toneladas
};


#endif