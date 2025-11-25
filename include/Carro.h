#ifndef CARRO_H
#define CARRO_H
#include "Veiculo.h"

/**
 * 
 * @brief Classe que representa um carro
 * 
 * @param placa placa do carro
 * @param marca marca do carro
 * @param numeroPortas quantidade de portas do carro
 * 
 */
class Carro : public Veiculo {
    public:
        Carro(std::string placa,std::string marca,size_t numeroPortas=4);
        virtual void mostrarInformacoes(std::ostream& out = std::cout) const;
        virtual double calcularCustoManutencao() const;
        virtual std::string getTipo();
    private:
        size_t numeroPortas;
};
#endif