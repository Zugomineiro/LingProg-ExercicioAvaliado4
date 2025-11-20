#ifndef CARRO_H
#define CARRO_H
#include "Veiculo.h"

class Carro : public Veiculo {
    public:
        Carro(std::string placa,std::string marca,size_t numeroPortas=4);
        virtual void mostrarInformacoes(std::ostream& out = std::cout) const;
        virtual double calcularCustoManutencao() const;
    private:
        size_t numeroPortas;
};
#endif