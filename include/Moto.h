#ifndef MOTO_H
#define MOTO_H

#include "Veiculo.h"

/**
 * 
 * @brief Classe que representa uma moto
 * 
 * @param placa placa da moto
 * @param marca marca da moto
 * @param cilindradas quantidade de cilindradas (cm³) da moto
 * 
 */
class Moto : public Veiculo{
    public:
        Moto(std::string placa, std::string marca, double cilindradas);
        virtual void mostrarInformacoes(std::ostream& out = std::cout) const;
        virtual double calcularCustoManutencao() const;
        virtual std::string getTipo();
    private:
        double cilindradas;
};

#endif