#ifndef CAMINHAO_H
#define CAMINHAO_H

#include "Veiculo.h"

/**
 * 
 * @brief Classe que representa um caminhao
 * 
 * @param placa placa do caminhao
 * @param marca marca do caminhao
 * @param capacidadeCarga capacidade de carga (em toneladas) do caminhao
 * 
 */
class Caminhao : public Veiculo{
    public:
        Caminhao(std::string placa,std::string marca,double capacidadeCarga);
        virtual void mostrarInformacoes(std::ostream& out = std::cout) const;
        virtual double calcularCustoManutencao() const;
        virtual std::string getTipo();
    private:
        double capacidadeCarga; // Em toneladas
};


#endif