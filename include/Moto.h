#ifndef MOTO_H
#define MOTO_H

#include "Veiculo.h"

class Moto : public Veiculo{
    public:
        Moto(std::string placa, std::string marca, double cilindradas);
        virtual void mostrarInformacoes(std::ostream& out = std::cout) const;
        virtual double calcularCustoManutencao() const;
    private:
        double cilindradas;
};

#endif