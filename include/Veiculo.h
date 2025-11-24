#ifndef VEICULO_H
#define VEICULO_H
#include <string>
#include <iostream>
#include "Excecoes.h"

class Veiculo{
    public:
        Veiculo(std::string placa,std::string marca);
        Veiculo();
        virtual void mostrarInformacoes(std::ostream& out = std::cout) const;
        virtual double calcularCustoManutencao() const;
        double getQuilometragem() const;
        double getCustoManutencao() const;
        std::string getPlaca() const;
        std::string getMarca() const;
        void setCustoManutencao(double custoManutencao);
        void setQuilometragem(double quilometragem);
        bool operator>(Veiculo& veiculo);
        bool operator<(Veiculo& veiculo);
        bool operator==(Veiculo& veiculo);
    private:
        std::string placa;
        std::string marca;
        double custoManutencao = 0;
        double quilometragem = 0;

};

std::ostream& operator<<(std::ostream& out, Veiculo& veiculo);

#endif