#ifndef VEICULO_H
#define VEICULO_H
#include <string>
#include <iostream>
#include "Excecoes.h"

/**
 * 
 * @brief Classe generica para representar um veiculo, serve de base para polimorfismo de outras classes.
 * 
 * @param placa placa do veiculo
 * @param marca marca do veiculo
 * 
 */
class Veiculo{
    public:
        Veiculo(std::string placa,std::string marca);
        virtual ~Veiculo(); // Serve apenas para que o compilador não reclame da falta de um destrutor virtual ao usar delete
        Veiculo();
        virtual void mostrarInformacoes(std::ostream& out = std::cout) const;
        virtual double calcularCustoManutencao() const;
        virtual std::string getTipo();
        double getQuilometragem() const;
        double getCustoManutencao() const;
        std::string getPlaca() const;
        std::string getMarca() const;
        void setCustoManutencao(double custoManutencao);
        void setQuilometragem(double quilometragem);
        bool operator>(Veiculo& veiculo);
        bool operator<(Veiculo& veiculo);
        bool operator==(Veiculo& veiculo);
        bool operator>(std::string placa);
        bool operator<(std::string placa);
        bool operator==(std::string placa);
        void operator()(double quilometragem);
    private:
        std::string placa;
        std::string marca;
        double custoManutencao = 0;
        double quilometragem = 0;

};

std::ostream& operator<<(std::ostream& out, Veiculo& veiculo);


#endif